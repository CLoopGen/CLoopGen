#include <stdio.h>

#include <inttypes.h>

typedef unsigned int UInt32;

typedef int Int32;

extern UInt32 *ftab;
extern Int32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int level1 = 1; level1 <= 256; level1++) {
        for (int level2 = 1; level2 <= 256; level2++) {
            int idx = (level1 - 1) * 256 + level2;
            if (idx >= 1 && idx <= 65536) {
                ftab[idx] += ftab[idx - 1];
            }
        }
    }
}
