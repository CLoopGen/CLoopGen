#include <stdio.h>

#include <inttypes.h>

typedef unsigned int UInt32;

typedef int Int32;

extern UInt32 *ftab;
extern Int32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i <= 65536; i += 2) {
        ftab[i] += ftab[i - 1];
        if (i + 1 <= 65536) {
            ftab[i + 1] += ftab[i];
        }
    }
}
