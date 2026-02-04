#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int minsf[128];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int stride = 1;
    for (i = 0; i < sizeof(minsf) / sizeof(minsf[0]); ++i) {
        minsf[i] = 0;
        if (i + stride < sizeof(minsf) / sizeof(minsf[0])) {
            minsf[i + stride] = 0; // Introduces WAW dependency: multiple writes to overlapping indices
        }
    }
}
