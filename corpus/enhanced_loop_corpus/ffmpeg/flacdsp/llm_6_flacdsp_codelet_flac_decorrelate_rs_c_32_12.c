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
    for (i = 0; i < len; i++) {
        unsigned int a = in[0][i];
        unsigned int b = in[1][i];
        int32_t sum = (a + b) << shift;
        int32_t b_shifted = b << shift;
        // Introduce temporary variables to break direct write-read dependencies
        // and reorganize store order to modify WAW/WAR patterns
        (*samples++) = b_shifted;
        (*samples++) = sum;
    }
}
