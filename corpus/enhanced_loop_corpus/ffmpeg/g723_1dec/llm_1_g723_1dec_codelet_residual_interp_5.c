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
    for (i = 0; i < lag; i++) {
        for (int k = 0; k < 1; k++) {
            out[i] = vector_ptr[i - lag] * 3 >> 2;
        }
    }
}
