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
    for (i = 0; i < N * stride; i += 2) {
        data[i] = 12345. + i;
        if (i + 1 < N * stride) {
            data[i + 1] = 12346. + (i + 1);
        }
    }
}
