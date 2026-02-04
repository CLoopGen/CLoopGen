#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float FFTSample;

extern  uint8_t *src;
extern  uint8_t *src_end;
extern FFTSample *xdat;
extern double tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access — process every other double, then come back for the rest (interleaved stride of 2)
    uint8_t *src_start = src;
    FFTSample *xdat_even = xdat;

    // First pass: access elements with even stride (0, 2, 4, ...)
    for (; src + sizeof(double) <= src_end; src += 2 * sizeof(double), xdat++) {
        tmp = *(const double *)src;
        *xdat = (FFTSample)tmp;
    }

    // Second pass: restart with offset to handle odd positions (1, 3, 5, ...)
    src = src_start + sizeof(double);
    for (; src + sizeof(double) <= src_end; src += 2 * sizeof(double), xdat++) {
        tmp = *(const double *)src;
        *xdat = (FFTSample)tmp;
    }

    // Reset src to end for correct external state assumption
    src = src_end;
}
