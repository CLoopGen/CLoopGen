#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int minsf[128];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    for (i = 0; i < sizeof(minsf) / sizeof(minsf[0]); i += 2) {
        minsf[i] = 0;
        if (i + 1 < sizeof(minsf) / sizeof(minsf[0])) {
            minsf[i + 1] = 0;
        }
    }
}
