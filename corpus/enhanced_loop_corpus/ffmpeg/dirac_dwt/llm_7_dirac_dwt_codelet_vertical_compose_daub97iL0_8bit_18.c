#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int width;
extern int i;
extern int16_t *b0;
extern int16_t *b1;
extern int16_t *b2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int16_t *restrict local_b1 = b1;
    const int16_t *restrict local_b0 = b0;
    const int16_t *restrict local_b2 = b2;
    int acc = 0;
    for (i = 0; i < width; i++) {
        int val = (unsigned int)(local_b0[i]) + (unsigned int)(local_b2[i]);
        int computed = (217 * val + 2048) >> 12;
        acc += computed;
        local_b1[i] = (unsigned int)(local_b1[i]) + acc;
    }
}
