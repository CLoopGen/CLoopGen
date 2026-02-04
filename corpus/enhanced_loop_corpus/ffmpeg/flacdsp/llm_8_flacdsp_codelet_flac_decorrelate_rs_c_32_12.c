#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t **in;
extern int len;
extern int shift;
extern int32_t *samples;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < len * 2; i += 2) {
    unsigned int a = in[0][i/2];
    unsigned int b = in[1][i/2];
    int32_t sum = a + b;
    (*samples++) = sum << shift;
    (*samples++) = b << shift;
    if (i + 1 < len * 2) {
        unsigned int a_next = in[0][(i/2)+1];
        unsigned int b_next = in[1][(i/2)+1];
        (*samples++) = (a_next + b_next) << shift;
        (*samples++) = b_next << shift;
    }
}
}
