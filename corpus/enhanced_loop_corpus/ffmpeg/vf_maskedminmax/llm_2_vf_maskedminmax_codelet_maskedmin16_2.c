#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int w;
extern  uint16_t *src;
extern  uint16_t *f1;
extern  uint16_t *f2;
extern uint16_t *dst;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    for (int x = 0; x < w; x += 2) {
        if (x + 1 < w) {
            // Process two elements with stride 2 for all arrays
            int idx = x;
            dst[idx] = ((src[idx] - f2[idx]) >= 0 ? (src[idx] - f2[idx]) : (-(src[idx] - f2[idx]))) < 
                       ((src[idx] - f1[idx]) >= 0 ? (src[idx] - f1[idx]) : (-(src[idx] - f1[idx]))) ? f2[idx] : f1[idx];
            
            idx = x + 1;
            dst[idx] = ((src[idx] - f2[idx]) >= 0 ? (src[idx] - f2[idx]) : (-(src[idx] - f2[idx]))) < 
                       ((src[idx] - f1[idx]) >= 0 ? (src[idx] - f1[idx]) : (-(src[idx] - f1[idx]))) ? f2[idx] : f1[idx];
        } else {
            // Handle odd-sized w
            dst[x] = ((src[x] - f2[x]) >= 0 ? (src[x] - f2[x]) : (-(src[x] - f2[x]))) < 
                     ((src[x] - f1[x]) >= 0 ? (src[x] - f1[x]) : (-(src[x] - f1[x]))) ? f2[x] : f1[x];
        }
    }
}
