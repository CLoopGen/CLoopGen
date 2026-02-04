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
    int temp1, temp2;
    for (i = 0; i < len; i++) {
        temp1 = coeff * in[i];
        temp2 = temp1 + 16384;
        out[i] = (temp2 >> 15);
    }
}
