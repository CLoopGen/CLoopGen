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
    size_t j;
    for (j = 0; j < N; j++) {
        size_t idx = j * stride;
        data[idx] = 12345. + idx;
        if (stride > 1) {
            data[idx + 1] = 12345. + idx + 1;
        }
    }
}
