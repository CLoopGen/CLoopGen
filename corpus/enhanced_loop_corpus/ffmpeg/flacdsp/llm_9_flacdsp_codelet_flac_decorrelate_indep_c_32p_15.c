#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t **in;
extern int channels;
extern int len;
extern int shift;
extern int32_t **samples;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 0; j < len; j++) {
        for (i = 0; i < channels; i += 2) {
            samples[i][j] = (int)((unsigned int)in[i][j] << shift);
            if (i + 1 < channels) {
                samples[i+1][j] = (int)((unsigned int)in[i+1][j] << shift) ^ 0x8000;
            }
        }
    }
}
