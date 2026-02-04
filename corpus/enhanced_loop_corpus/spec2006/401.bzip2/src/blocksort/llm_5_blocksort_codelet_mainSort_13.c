#include <stdio.h>

#include <inttypes.h>

typedef unsigned int UInt32;

typedef int Int32;

extern UInt32 *ftab;
extern Int32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 65536; i >= 0; i--) {
        if (i == 32768) {
            ftab[i] = 0;
        } else {
            ftab[i] = 0;
        }
    }
}
