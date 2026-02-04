#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

extern int16_t *out;
extern  int16_t *in;
extern integer len;
extern int i;
extern int coeff;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int prev_index = 0;
    for (i = 1; i < len; i++) {
        out[i] = (((coeff * in[prev_index]) + 16384) >> 15);
        prev_index = i;
    }
    if (len > 0) {
        out[0] = (((coeff * in[0]) + 16384) >> 15);
    }
}
