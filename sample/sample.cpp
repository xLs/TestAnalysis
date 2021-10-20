// The Worst possible coder! please contribute!
//




#include "stdio.h"
#include <memory>
#include <string>


class Base
{
private:
    int _id;
    char* _leak;
public:
    Base()  // noexcept
    {
        _id = ClassID(); // call vfunction from constructor
        _leak = new char[255];
    }
    ~Base() // should be virtual!!
    {
        delete _leak;
    }
    virtual int ClassID() { return 1; }
    int GetID() { return _id; }
};


class Derived : public Base
{
public:
	Derived()
	{
		
	}
    ~Derived()  // base does not have a virtual destructor!
	{
		// will not call base!
	}
    virtual int ClassID()  { return 2; } // noexcept?
};

int useretval(int& uninit)
{
    
    uninit++;
    return uninit;
}

void LeakSomeMemory()
{
    std::string* leak = new std::string();
    leak->append("hello world");
}



std::string& retBadRef(const std::string& a, const std::string& b)
{
    std::string byrefret;
    byrefret += a;
    byrefret += b;
    return byrefret;
}


class A // no virtual destructor?
{
public:
    virtual std::string GetName() const { return "A"; }
    
};

class B : public A
{
public:
    virtual std::string GetName()  const { return "B"; } // where is override?
    
};

void badfunc(A a) // oh this happens way too often!
{
    printf("badfunc: %s\n",a.GetName().c_str());
    
}

void goodfunc(A& a) // ok by  ref, should be const?
{
    printf("goodfunc: %s\n", a.GetName().c_str());

}


static int double_up = 0;   // lets define this in another scope

int main(int argc, const char* argv[])
{
    int uninitialized_value;
    int shadowed = 5;
    int unusedvariable = 0;

    int mispell = 23; // bad speling behiend the keiboard
    mispell++;

    int __bad_name_of_variable = 0; // __ should be exlusive to compiler stuff

	__bad_name_of_variable++;


	// shadowed value, best practice
    for (int shadowed = 0; shadowed < 10; shadowed++ )
    {
        printf("wrong type value = %llu\n", shadowed);
    }

    useretval(uninitialized_value);


    int double_up = 23; // defined globally 
    if(shadowed & 4 == 0) // check operator precedence
    {
        printf("test");
    }

    
    if(shadowed = 1) // accidental assigning
    {
        shadowed = 12;
    }

    if(uninitialized_value == 6)
    {
        printf("test2");
    }


    int fx = 7; // could be const
    int fy = 2; // could be const
    float fval = fx / fy;   // unpromoted float

    fval = fval;

    char* scalar = new char[100];

    delete scalar; // not scalar delete


    switch(shadowed)
    {
	    case 1:
            shadowed = 4;
    	break;
	    case 2:
        {
            int shadowed = 1;
        }
              break;
	    case 3:
        default:
        case 4:
            printf("yessir");
    }


    Derived derived;
    printf("Derived Class id: %d", derived.GetID());
#ifndef _WIN32
    std::auto_ptr<Derived> a(new Derived); // deprecated
#endif

    LeakSomeMemory();

    
    try
    {
        auto str = retBadRef("test", "test2");     
        printf("strings", str.c_str());     // oops, forgot expected argument in varg/
    }
    catch (...)
    {
    }


    // lets do something bad but very common
    B b;
    badfunc(b);     // nasty
    goodfunc(b);

    return 0;
}

