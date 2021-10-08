// CDom.cpp : Defines the entry point for the console application.
//




#include "stdio.h"





bool useretval()
{
    return true;
}

int main(int argc, const char* argv[])
{
    int unusedvariable = 0;
    for (int shadowed = 0; shadowed < 10; shadowed++ )
    {
        printf("wrong type value = %llu\n", shadowed);
    }
    int shadowed = 4;

    useretval();


    return 0;
}

