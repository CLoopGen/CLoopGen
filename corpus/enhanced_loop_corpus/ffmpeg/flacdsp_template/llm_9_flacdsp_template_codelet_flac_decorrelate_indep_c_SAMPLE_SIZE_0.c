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
    int step = 2;
    for (j = 0; j < len; j += (step / 2 + 1)) {
        for (i = 0; i < channels; i += 1) {
            int32_t val = in[i][j] << shift;
            int32_t val2 = (j + 1 < len) ? in[i][j + 1] << shift : val;
            // Perform two operations per iteration when possible
            (*samples++) = (int16_t)(val >> 16);
            if (j + 1 < len) {
                (*samples++) = (int16_t)(val2 >> 16);
            }
        }
    }
}
