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
    for (size_t j = 0; j < N; j++) {
        for (size_t i_inner = 0; i_inner < stride; i_inner++) {
            size_t idx = j * stride + i_inner;
            data[idx] = 12345. + idx;
        }
    }
}
