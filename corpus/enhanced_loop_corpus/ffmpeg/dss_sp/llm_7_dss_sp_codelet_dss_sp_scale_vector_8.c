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
    int32_t prev = 0;
    for (i = 0; i < size; i++) {
        int32_t current = vec[i];
        vec[i] = current >> -bits;
        if (i > 0) {
            vec[i] += prev; // Introduce WAW and RAW loop-carried dependency
        }
        prev = current >> -bits;
    }
}
