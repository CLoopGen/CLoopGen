#include <stdio.h>

#include <inttypes.h>

typedef int Int32;

extern Int32 ftab[257];
extern Int32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    Int32 temp[257];
    for (i = 1; i < 257; i++)
        temp[i] = ftab[i] + ftab[i - 1];
    for (i = 1; i < 257; i++)
        ftab[i] = temp[i];
}
