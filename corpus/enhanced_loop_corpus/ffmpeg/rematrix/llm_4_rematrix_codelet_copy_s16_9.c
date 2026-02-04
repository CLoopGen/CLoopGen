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
    for (i = 0; i < len; i++) {
        int temp = coeff * in[i];
        if (temp >= 0) {
            out[i] = (temp + 16384) >> 15;
        }
    }
}
