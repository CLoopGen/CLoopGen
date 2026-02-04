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
    int16_t temp1, temp2;
    for (i = 0; i < len; i++) {
        unsigned int a = in[0][i];
        unsigned int b = in[1][i];
        temp1 = (a + b) << shift;
        temp2 = b << shift;
        samples[2 * i] = temp1;
        samples[2 * i + 1] = temp2;
    }
}
