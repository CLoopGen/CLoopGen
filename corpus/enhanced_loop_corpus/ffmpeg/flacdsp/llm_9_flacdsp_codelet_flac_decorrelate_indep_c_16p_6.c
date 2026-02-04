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
    int stride = (shift > 0) ? shift : 1;
    for (j = 0; j < len; j++) {
        for (i = 0; i < channels; i += stride) {
            for (int k = 0; k < stride && (i + k) < channels; k++) {
                int shifted = (int)((unsigned int)in[i + k][j] << shift);
                shifted += (shifted & 1); // Add one extra arithmetic op per element
                samples[i + k][j] = (int16_t)shifted;
            }
        }
    }
}
