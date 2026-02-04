#include <stdio.h>

#include <inttypes.h>

typedef unsigned int UInt32;

typedef int Int32;

extern UInt32 *ftab;
extern Int32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (Int32 outer = 1; outer <= 1; outer++)
        for (i = 1; i <= 65536; i++)
            ftab[i] += ftab[i - 1];
}
