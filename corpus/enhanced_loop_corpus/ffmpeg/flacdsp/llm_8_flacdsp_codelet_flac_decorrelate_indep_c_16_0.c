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
    for (j = 0; j < len; j++) {
        for (i = 0; i < channels; i += 2) {
            if (i + 1 < channels) {
                int32_t val1 = in[i][j];
                int32_t val2 = in[i+1][j];
                *samples++ = (int16_t)((unsigned int)val1 << shift);
                *samples++ = (int16_t)((unsigned int)val2 << shift);
            } else {
                *samples++ = (int16_t)((unsigned int)in[i][j] << shift);
            }
        }
    }
}
