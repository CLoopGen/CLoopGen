#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t **in;
extern int channels;
extern int len;
extern int shift;
extern int32_t *samples;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 0; j < len && channels > 0; j++) {
        for (i = 0; i < channels; i++) {
            int32_t val = in[i][j];
            if (val >= 0) {
                (*samples++) = (int)((unsigned int)val << shift);
            } else {
                (*samples++) = 0;
            }
        }
    }
}
