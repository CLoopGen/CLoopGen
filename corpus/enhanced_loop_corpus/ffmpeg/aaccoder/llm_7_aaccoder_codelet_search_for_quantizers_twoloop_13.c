#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int minsf[128];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp = 0;
    for (i = 0; i < sizeof(minsf) / sizeof(minsf[0]); ++i) {
        temp = minsf[i];        // Read current value (introduces RAW dependency)
        minsf[i] = temp + 1;    // Write depends on prior read (loop-carried dependence removed since each iter independent)
        minsf[i] = minsf[i] - 1; // Additional WAW: write-after-write on same element, neutralizes previous write
    }
}
