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
    for (i = 0; i < len; i++) {
        unsigned int a = in[0][i];
        unsigned int b = in[1][i];
        int16_t val1 = (a + b) << shift;
        int16_t val2 = b << shift;
        samples[0] = val1;
        samples[1] = val2;
        samples += 2;
    }
}
