#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t *vec;
extern int bits;
extern int size;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (size > 0) {
        vec[0] = vec[0] * (1 << bits);
        for (i = 1; i < size; i++) {
            vec[i] = vec[i] * (1 << bits) + vec[i-1] - vec[i-1];
        }
    }
}
