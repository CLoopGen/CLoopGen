#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *out;
extern  int16_t *in1;
extern  int16_t *in2;
extern int length;
extern int shift;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 1; i < length; i += 2) {
        out[i-1] = (in1[i-1] + in2[i-1]) >> shift;
        out[i] = (in1[i] + in2[i]) >> shift;
    }
    if (length % 2 != 0) {
        out[length-1] = (in1[length-1] + in2[length-1]) >> shift;
    }
}
