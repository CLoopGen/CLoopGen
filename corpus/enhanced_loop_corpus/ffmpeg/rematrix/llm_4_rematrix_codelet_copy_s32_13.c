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
    for (i = 0; i < len; i++) {
        int32_t temp = in[i];
        if (temp != 0) {
            out[i] = (((coeff * temp) + 16384) >> 15);
        } else {
            out[i] = 0;
        }
    }
}
