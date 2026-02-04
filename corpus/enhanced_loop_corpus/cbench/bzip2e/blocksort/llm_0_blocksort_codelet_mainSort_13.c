#include <stdio.h>

#include <inttypes.h>

typedef unsigned int UInt32;

typedef int Int32;

extern UInt32 *ftab;
extern Int32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (Int32 j = 0; j < 1; j++)
    for (i = 65536; i >= 0; i--)
        ftab[i] = 0;
}
