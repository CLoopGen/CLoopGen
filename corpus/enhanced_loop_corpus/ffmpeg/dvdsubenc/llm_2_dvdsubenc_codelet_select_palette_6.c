#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int out_palette[4];
extern int out_alpha[4];
extern int i;
extern int selected[4];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with step of 2, unrolled to process two elements per iteration
    for (i = 0; i < 4; i += 2) {
        int idx0 = i;
        int idx1 = i + 1;
        
        // Process element at idx0
        out_palette[idx0] = selected[idx0] ? (selected[idx0] - 1) & 15 : 0;
        out_alpha[idx0] = !selected[idx0] ? 0 : selected[idx0] < 17 ? 128 : 255;
        
        // Process element at idx1 if within bounds
        if (idx1 < 4) {
            out_palette[idx1] = selected[idx1] ? (selected[idx1] - 1) & 15 : 0;
            out_alpha[idx1] = !selected[idx1] ? 0 : selected[idx1] < 17 ? 128 : 255;
        }
    }
}
