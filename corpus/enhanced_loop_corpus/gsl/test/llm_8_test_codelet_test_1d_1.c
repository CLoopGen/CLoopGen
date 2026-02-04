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
    for (i = stride; i < N * stride; i += stride) {
        size_t j;
        for (j = 1; j < stride && (i - stride + j) < N * stride; j++) {
            status |= (data[i - stride + j] != (12345. + (i - stride + j)));
        }
    }
}
