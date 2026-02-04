#include <stdio.h>

#include <inttypes.h>

typedef unsigned int UInt32;

typedef int Int32;

extern UInt32 *ftab;
extern Int32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    UInt32 *local_ftab = ftab;
    for (i = 1; i <= 65536; i++) {
        local_ftab[i] = local_ftab[i] + local_ftab[i - 1];
    }
    for (i = 1; i <= 65536; i++) {
        ftab[i] = local_ftab[i];
    }
}
