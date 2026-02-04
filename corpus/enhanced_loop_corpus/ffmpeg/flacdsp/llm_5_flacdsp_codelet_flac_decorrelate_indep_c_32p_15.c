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
        int valid_channel = (shift >= 0 && shift < 32);
        for (i = 0; i < channels; i++) {
            if (valid_channel) {
                samples[i][j] = (int)((unsigned int)in[i][j] << shift);
            } else {
                samples[i][j] = 0;
            }
        }
    }
}
