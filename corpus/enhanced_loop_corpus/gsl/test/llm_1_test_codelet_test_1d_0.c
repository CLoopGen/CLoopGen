#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t N;
extern size_t stride;
extern size_t i;
extern double *data;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (size_t block = 0; block < N * stride; block += stride) {
        for (size_t offset = 0; offset < stride && (block + offset) < N * stride; offset++) {
            size_t idx = block + offset;
            data[idx] = 12345. + idx;
        }
    }
}
