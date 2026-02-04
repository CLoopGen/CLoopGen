#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern int stride;
extern int width;
extern int height;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access by transposing the iteration order (access down columns first)
    uint8_t *d = dst;
    uint8_t *s = src;
    // Transpose inner loop to iterate vertically per column, improving spatial locality in some cache designs
    for (j = 0; j < width; j++) {
        uint8_t *col_s = s + j;
        uint8_t *col_d = d + j;
        for (i = 0; i < height; i++) {
            if (j + 1 < width) {  // Ensure j+1 is within bounds
                *col_d = (uint8_t)((*col_d + (((3 * *col_s + 2 * *(col_s + 1) + 
                                 4 * *(col_s + stride) + 3 * *(col_s + stride + 1) + 6) * 2731) >> 15) + 1) >> 1);
            } else {
                // Fallback when j+1 is out of bounds
                *col_d = (uint8_t)((*col_d + (((3 * *col_s + 2 * *col_s + 
                                 4 * *(col_s + stride) + 3 * *(col_s + stride) + 6) * 2731) >> 15) + 1) >> 1);
            }
            col_s += stride;
            col_d += stride;
        }
    }
}
