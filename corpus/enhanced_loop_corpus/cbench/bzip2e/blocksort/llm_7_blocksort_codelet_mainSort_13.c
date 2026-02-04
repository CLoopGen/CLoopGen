#include <stdio.h>

#include <inttypes.h>

typedef unsigned int UInt32;

typedef int Int32;

extern UInt32 *ftab;
extern Int32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 65536; i >= 0; i -= 2) {
        ftab[i] = 0;
        if (i > 0) {
            ftab[i-1] = 0;
        }
    }
}
