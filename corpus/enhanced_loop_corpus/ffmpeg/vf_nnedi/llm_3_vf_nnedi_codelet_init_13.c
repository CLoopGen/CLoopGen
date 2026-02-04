#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int j;
extern int k;
extern int *offt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with reverse traversal and stride of 2, writing only to even indices
    for (j = 3; j >= 0; j--) {
        for (k = 62; k >= 0; k -= 2) {
            int idx = j * 64 + k;
            offt[idx] = ((k >> 3) << 5) + ((j & 3) << 3) + (k & 7);
        }
    }
}
