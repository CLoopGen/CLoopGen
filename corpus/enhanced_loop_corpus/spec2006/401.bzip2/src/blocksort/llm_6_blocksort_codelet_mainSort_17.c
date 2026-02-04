#include <stdio.h>

#include <inttypes.h>

typedef unsigned int UInt32;

typedef int Int32;

extern UInt32 *ftab;
extern Int32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    UInt32 temp = 0;
    for (i = 1; i <= 65536; i++) {
        temp = ftab[i - 1];
        ftab[i] += temp;
    }
}
