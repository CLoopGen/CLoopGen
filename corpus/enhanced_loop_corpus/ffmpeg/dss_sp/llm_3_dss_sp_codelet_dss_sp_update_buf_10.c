#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t *vector;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive backward write with offset shift
    int32_t *src = &vector[114];
    int32_t *dst = &vector[114 + 72];
    for (i = 114; i > 0; i--) {
        *(dst--) = *(src--);
    }
}
