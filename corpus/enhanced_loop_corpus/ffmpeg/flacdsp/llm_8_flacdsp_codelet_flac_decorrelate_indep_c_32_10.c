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
    int stride = channels * len;
    for (i = 0; i < stride; i++) {
        int ch = i % channels;
        int pos = i / channels;
        if (pos < len) {
            (*samples++) = (int)((unsigned int)in[ch][pos] << shift);
        }
    }
}
