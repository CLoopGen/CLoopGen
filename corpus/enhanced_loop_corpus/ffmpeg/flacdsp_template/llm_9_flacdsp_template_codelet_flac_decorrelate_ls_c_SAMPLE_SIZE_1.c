#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t **in;
extern int len;
extern int shift;
extern int16_t *samples;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < len * 2; i++) {
        int idx = i / 2;
        unsigned int a = in[0][idx];
        unsigned int b = in[1][idx];
        if (i % 2 == 0) {
            (*samples++) = (a << shift) + (b >> 1);
        } else {
            (*samples++) = ((a - b) << shift) - (a >> 2);
        }
    }
}
