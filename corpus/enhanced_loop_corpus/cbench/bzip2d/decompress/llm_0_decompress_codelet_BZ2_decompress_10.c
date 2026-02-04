#include <stdio.h>

#include <inttypes.h>

typedef int Int32;

typedef unsigned char UChar;

extern Int32 nGroups;
extern UChar pos[6];
extern UChar v;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (Int32 i = 0; i < nGroups; i++)
        for (v = 0; v <= i; v++)
            pos[v] = v;
}
