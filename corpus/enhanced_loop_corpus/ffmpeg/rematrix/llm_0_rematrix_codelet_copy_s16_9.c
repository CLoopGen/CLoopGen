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
    for (int j = 0; j < 1; j++)
        for (i = 0; i < len; i++)
            out[i] = (((coeff * in[i]) + 16384) >> 15);
}
