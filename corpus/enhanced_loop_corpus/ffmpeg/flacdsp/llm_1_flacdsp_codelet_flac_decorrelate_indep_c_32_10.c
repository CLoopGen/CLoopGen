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
    for (j = 0; j < len; j++)
        for (i = 0; i < channels; i++)
            for (int k = 0; k < 1; k++)
                (*samples++) = (int)((unsigned int)in[i][j] << shift);
}
