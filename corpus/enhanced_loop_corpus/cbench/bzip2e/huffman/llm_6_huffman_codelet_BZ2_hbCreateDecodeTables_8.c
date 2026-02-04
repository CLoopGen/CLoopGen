#include <stdio.h>

#include <inttypes.h>

typedef int Int32;

extern Int32 *base;
extern Int32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    Int32 temp[23];
    for (i = 1; i < 23; i++)
        temp[i] = base[i - 1];
    for (i = 1; i < 23; i++)
        base[i] += temp[i];
}
