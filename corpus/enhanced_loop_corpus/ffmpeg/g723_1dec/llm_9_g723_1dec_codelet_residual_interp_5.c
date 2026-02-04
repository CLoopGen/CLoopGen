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
    int j;
    for (i = 0; i < lag && lag > 0; i++) {
        int16_t val = vector_ptr[i - lag];
        out[i] = (val * val + val * 4) >> 2;
        for (j = 0; j < 2; j++) {
            val = (val + 1) & 0x7FFF;
        }
    }
}
