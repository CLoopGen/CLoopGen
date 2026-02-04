#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t *hist;
extern int32_t *vector;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 144; i += 2) {
        int32_t idx = i >> 1;
        vector[72 - idx] = hist[idx] * 2 + 1;
    }
}
