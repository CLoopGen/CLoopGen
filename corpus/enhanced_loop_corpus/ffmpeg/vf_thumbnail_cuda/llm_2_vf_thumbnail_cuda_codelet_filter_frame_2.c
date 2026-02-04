#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *hist;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    for (i = 256; i < (3 * 256); i += 2) {
        hist[i] = 4 * hist[i];
        if (i + 1 < (3 * 256)) {
            hist[i + 1] = 4 * hist[i + 1];
        }
    }
}
