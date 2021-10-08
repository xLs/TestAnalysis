// CDom.cpp : Defines the entry point for the console application.
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
    Base()
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
    ~Derived()
	{
		// will not call base!
	}
    virtual int ClassID() { return 2; }
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


class A
{
public:
    virtual std::string GetName() const { return "A"; }
    
};

class B : public A
{
public:
    virtual std::string GetName() const { return "B"; }
    
};

void badfunc(A a) // should be by ref
{
    printf("badfunc: %s\n",a.GetName().c_str());
    
}

void goodfunc(A& a) // ok by  ref
{
    printf("goodfunc: %s\n", a.GetName().c_str());

}


int main(int argc, const char* argv[])
{
    int uninitialized_value;
    int shadowed = 5;
    int unusedvariable = 0;

	// shadowed value, best practice
    for (int shadowed = 0; shadowed < 10; shadowed++ )
    {
        printf("wrong type value = %llu\n", shadowed);
    }

    useretval(uninitialized_value);

    // check operator precedence
    if(shadowed & 4 == 0)
    {
        printf("test");
    }

    // accidental assigning
    if(shadowed = 1)
    {
        shadowed = 12;
    }

    if(uninitialized_value == 6)
    {
        printf("test2");
    }


    int fx = 7;
    int fy = 2;
    float fval = fx / fy;   // un promoted float

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
        printf("strings", str.c_str());
    }
    catch (...)
    {
    }


    B b;
    badfunc(b);
    goodfunc(b);

    return 0;
}

