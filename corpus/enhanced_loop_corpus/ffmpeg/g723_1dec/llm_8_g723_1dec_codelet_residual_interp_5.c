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
    for (i = 0; i < lag; i += 2) {
        if (i < lag) out[i] = (vector_ptr[i - lag] * 5 + 1) >> 3;
        if (i + 1 < lag) out[i + 1] = (vector_ptr[i + 1 - lag] * 7 - 2) >> 2;
    }
}
