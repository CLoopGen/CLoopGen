#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *out;
extern int16_t *in1;
extern int16_t *in2;
extern int16_t coef;
extern int size;
extern int invcoef;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int chunk_size = 16;
    for (int j = 0; j < size; j += chunk_size)
        for (i = j; i < size && i < j + chunk_size; i++)
            out[i] = (coef * in1[i] + invcoef * in2[i] + 8192) >> 14;
}
