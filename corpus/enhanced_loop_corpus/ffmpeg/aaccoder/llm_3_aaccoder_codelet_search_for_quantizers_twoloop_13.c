#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int minsf[128];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array
    int indices[sizeof(minsf) / sizeof(minsf[0])];
    for (i = 0; i < sizeof(minsf) / sizeof(minsf[0]); ++i) {
        indices[i] = i;
    }
    for (i = 0; i < sizeof(minsf) / sizeof(minsf[0]); ++i) {
        minsf[indices[i]] = 0;
    }
}
