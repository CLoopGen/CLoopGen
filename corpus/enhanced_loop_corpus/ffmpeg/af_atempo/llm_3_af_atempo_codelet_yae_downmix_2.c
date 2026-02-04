#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float FFTSample;

extern  uint8_t *src;
extern  uint8_t *src_end;
extern FFTSample *xdat;
extern int16_t tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access - process every other int16_t element, then come back
    size_t total_elements = (src_end - src) / sizeof(int16_t);
    size_t stride = 2;
    size_t offset;

    // First pass: process even indices with stride of 2
    for (offset = 0; offset < total_elements; offset += stride, xdat++) {
        const uint8_t* current_src = src + offset * sizeof(int16_t);
        tmp = *(const int16_t*)current_src;
        *xdat = (FFTSample)tmp;
    }

    // Second pass: process odd indices (strided pattern)
    for (offset = 1; offset < total_elements; offset += stride, xdat++) {
        const uint8_t* current_src = src + offset * sizeof(int16_t);
        tmp = *(const int16_t*)current_src;
        *xdat = (FFTSample)tmp;
    }
}
