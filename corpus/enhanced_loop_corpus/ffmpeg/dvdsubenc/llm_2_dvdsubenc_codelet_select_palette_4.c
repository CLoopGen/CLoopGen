#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int hits[33];
extern int i;
extern int j;
extern int selected[4];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access pattern
    // Instead of scanning hits[0..32] sequentially, we access with a stride of 4 (wrapping if needed)
    for (i = 0; i < 4; i++) {
        int stride = 4;
        for (j = 0; j < 33; j += stride) {
            int idx = j % 33; // Wrap-around to stay within bounds
            if (hits[idx] > hits[selected[i]])
                selected[i] = idx;
        }
        hits[selected[i]] = 0;
    }
}
