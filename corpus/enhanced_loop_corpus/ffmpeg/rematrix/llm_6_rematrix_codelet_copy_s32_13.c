#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

extern int32_t *out;
extern  int32_t *in;
extern integer len;
extern int i;
extern int64_t coeff;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int64_t temp;
    for (i = 0; i < len; i++) {
        temp = coeff * in[i];
        out[i] = (temp + 16384) >> 15;
    }
}
