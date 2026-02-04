#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t **in;
extern int channels;
extern int len;
extern int shift;
extern int16_t **samples;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access - process elements with stride of 2, then handle remainder
    int j, i;
    int stride = 2;
    for (j = 0; j < len; j += stride) {
        for (i = 0; i < channels; i++) {
            int j1 = j;
            int j2 = j + 1;
            if (j1 < len) {
                samples[i][j1] = (int)((unsigned int)in[i][j1] << shift);
            }
            if (j2 < len) {
                samples[i][j2] = (int)((unsigned int)in[i][j2] << shift);
            }
        }
    }
}
