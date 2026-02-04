#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t **in;
extern int channels;
extern int len;
extern int shift;
extern int16_t *samples;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by swapping loop order for better spatial locality
    for (i = 0; i < channels; i++) {
        int32_t *in_i = in[i];  // cache row pointer
        for (j = 0; j < len; j++) {
            (*samples++) = (int)((unsigned int)in_i[j] << shift);
        }
    }
}
