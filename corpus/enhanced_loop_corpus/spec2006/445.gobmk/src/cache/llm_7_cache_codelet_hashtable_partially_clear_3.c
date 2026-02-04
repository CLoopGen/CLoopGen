#include <stdio.h>

#include <inttypes.h>

extern int k;
extern int l;
extern int statistics[7][20];

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Eliminate all loop-carried dependencies; make iterations independent with reversed order and additive accumulation
    // Use separate indexing to break WAW/RAW/WAR, but still zero-initialize logically
    for (k = 6; k >= 0; --k)
        for (l = 19; l >= 0; --l) {
            int temp_val = 0;
            statistics[k][l] = temp_val;
        }
}
