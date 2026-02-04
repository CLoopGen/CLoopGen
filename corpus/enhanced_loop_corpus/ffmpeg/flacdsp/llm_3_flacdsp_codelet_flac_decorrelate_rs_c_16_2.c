#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t **in;
extern int len;
extern int shift;
extern int16_t *samples;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided access with reversed and alternating input pattern (stride of 2)
    int16_t *s = samples;
    int stride = 2;
    for (i = 0; i < len; i += stride) {
        if (i + 1 < len) {
            // Access pairs in reverse order: [i+1], then [i]
            unsigned int a1 = in[0][i + 1];
            unsigned int b1 = in[1][i + 1];
            unsigned int a0 = in[0][i];
            unsigned int b0 = in[1][i];

            (*s++) = (a0 + b0) << shift;
            (*s++) = b0 << shift;
            (*s++) = (a1 + b1) << shift;
            (*s++) = b1 << shift;
        } else {
            // Handle odd-length tail
            unsigned int a = in[0][i];
            unsigned int b = in[1][i];
            (*s++) = (a + b) << shift;
            (*s++) = b << shift;
        }
    }
    samples = s; // Update global samples pointer
}
