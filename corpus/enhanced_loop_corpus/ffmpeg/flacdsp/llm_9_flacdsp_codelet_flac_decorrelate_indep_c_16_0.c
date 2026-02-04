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
    int step = (shift > 0) ? 1 : 1;
    int limit = len * channels;
    for (int idx = 0; idx < limit; idx += step) {
        i = idx % channels;
        j = idx / channels;
        if (j < len) {
            int32_t temp = in[i][j];
            unsigned int shifted = (unsigned int)temp << shift;
            *samples++ = (int16_t)(shifted & 0xFFFF);
        }
    }
}
