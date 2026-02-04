#include <stdio.h>

#include <inttypes.h>

typedef unsigned int UInt32;

typedef int Int32;

extern UInt32 *bhtab;
extern Int32 nblock;
extern Int32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 32; i += 2) {
        for (int j = 0; j < 2 && (i + j) < 32; j++) {
            int idx = i + j;
            bhtab[(nblock + 2 * idx) >> 5] |= (1 << ((nblock + 2 * idx) & 31));
            bhtab[(nblock + 2 * idx + 1) >> 5] &= ~(1 << ((nblock + 2 * idx + 1) & 31));
        }
    }
}
