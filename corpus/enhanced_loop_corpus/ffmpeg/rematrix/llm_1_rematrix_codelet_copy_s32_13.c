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
    for (int j = 0; j < len; j++) {
        int idx = j;
        out[idx] = (((coeff * in[idx]) + 16384) >> 15);
    }
}
