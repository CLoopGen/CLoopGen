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
    for (j = 0; j < len; j++) {
        int32_t temp_val;
        for (i = 0; i < channels; i++) {
            temp_val = in[i][j]; // Introduce temporary to create intra-iteration dependency (RAW)
            (samples[i][j]) = (int)((unsigned int)temp_val << shift);
        }
    }
}
