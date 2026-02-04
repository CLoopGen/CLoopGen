#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t out_cb_unnorm[256];
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    for (int j = 0; j < 256; j += 2) {
        out_cb_unnorm[j] = -2047;
        if (j + 1 < 256) {
            out_cb_unnorm[j + 1] = -2047;
        }
    }
}
