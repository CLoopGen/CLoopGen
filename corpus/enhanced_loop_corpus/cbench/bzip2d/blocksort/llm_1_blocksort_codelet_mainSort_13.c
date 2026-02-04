#include <stdio.h>

#include <inttypes.h>

typedef unsigned int UInt32;

typedef int Int32;

extern UInt32 *ftab;
extern Int32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (Int32 outer = 65536; outer >= 0; outer -= 256) {
        for (i = outer; i > outer - 256 && i >= 0; i--)
            ftab[i] = 0;
    }
}
