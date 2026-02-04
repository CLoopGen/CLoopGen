#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *out;
extern int lag;
extern int i;
extern int16_t *vector_ptr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i < lag; i++)
        out[i] = out[i - 1] + (vector_ptr[i - lag] * 3 >> 2);
    if (lag > 0)
        out[0] = vector_ptr[-lag] * 3 >> 2;
}
