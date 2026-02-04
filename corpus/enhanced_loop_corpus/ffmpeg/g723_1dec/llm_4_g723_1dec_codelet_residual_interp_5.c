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
    if (lag <= 0) return;
    for (i = 0; i < lag; i++) {
        out[i] = vector_ptr[i - lag] * 3 >> 2;
    }
}
