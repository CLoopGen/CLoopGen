#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t N;
extern size_t stride;
extern size_t i;
extern double *data;
extern int status;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t j;
    for (j = stride; j < N * stride; j += stride) {
        size_t k = j - 1;
        if (k % stride != 0)
            k = k % stride;
        status |= (data[k] != (12345. + k));
    }
}
