#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int tmsize_t;

extern tmsize_t cc;
extern tmsize_t stride;
extern tmsize_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    tmsize_t *access_pattern = (tmsize_t*)malloc(sizeof(tmsize_t) * cc);
    if (!access_pattern) return;
    for (tmsize_t j = 0; j < cc; j += stride) {
        tmsize_t idx = (j * 2) % cc; // Strided indirect access: map j to non-consecutive indices
        access_pattern[idx] = j;     // Simulate write through indirect, strided pattern
    }
    free(access_pattern);
    i += stride; // Progress i to satisfy termination condition eventually
}
