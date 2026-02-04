#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int dst_linesizes[4];
extern  int src_linesizes[4];
extern ptrdiff_t dst_linesizes1[4];
extern ptrdiff_t src_linesizes1[4];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access (stride of 2), processing even indices first, then odd
    for (i = 0; i < 2; i++) {
        int idx = i * 2; // Stride of 2: access 0, 2
        dst_linesizes1[idx] = dst_linesizes[idx];
        src_linesizes1[idx] = src_linesizes[idx];
        
        if (idx + 1 < 4) {
            dst_linesizes1[idx + 1] = dst_linesizes[idx + 1];
            src_linesizes1[idx + 1] = src_linesizes[idx + 1];
        }
    }
}
