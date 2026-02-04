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
        int valid_channel_found = 0;
        for (i = 0; i < channels; i++) {
            int32_t val = in[i][j];
            if ((val >> shift) >= -16384 && (val >> shift) <= 16383) {
                (*samples++) = (int)((unsigned int)val << shift);
                valid_channel_found = 1;
            }
        }
        if (!valid_channel_found) {
            (*samples++) = 0;
        }
    }
}
