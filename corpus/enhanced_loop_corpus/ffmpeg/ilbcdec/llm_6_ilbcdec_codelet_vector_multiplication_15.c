#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *out;
extern  int16_t *in;
extern  int16_t *win;
extern int length;
extern int shift;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int16_t accumulator = 0;
    for (int i = 0; i < length; i++) {
        accumulator += in[i] * win[i];
        out[i] = accumulator >> shift;
        accumulator = out[i]; // Introduce WAW and RAW dependency; loop-carried dependence on accumulator
    }
}
