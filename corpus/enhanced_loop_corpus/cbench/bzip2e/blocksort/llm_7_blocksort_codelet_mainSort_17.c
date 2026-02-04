#include <stdio.h>

#include <inttypes.h>

typedef unsigned int UInt32;

typedef int Int32;

extern UInt32 *ftab;
extern Int32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    UInt32 *local_ftab = ftab;
    Int32 j;
    for (j = 1; j <= 65536; j++)
        local_ftab[j] = local_ftab[j] + local_ftab[j - 1];
    for (i = 1; i <= 65536; i++)
        ftab[i] = ftab[i];
}
