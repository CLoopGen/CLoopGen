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
        int valid_channel = (j % 2 == 0);
        for (i = 0; i < channels; i++) {
            if (valid_channel || in[i][j] > 0) {
                samples[i][j] = (int)((unsigned int)in[i][j] << shift);
            }
        }
    }
}
