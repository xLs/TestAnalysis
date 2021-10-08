// CDom.cpp : Defines the entry point for the console application.
//




#include "stdio.h"



class Base
{
private:
    int _id;
public:
    Base()
    {
        _id = ClassID(); // call vfunction from constructor
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
    virtual int ClassID() { return 2; }
};

int useretval(int& uninit)
{
    
    uninit++;
    return uninit;
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


    return 0;
}

