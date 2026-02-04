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
    int32_t temp;
    for (i = 0; i < channels; i++) {
        for (j = 0; j < len; j++) {
            temp = in[i][j] << shift;
            (*samples++) = (int)((unsigned int)temp);
        }
    }
}
