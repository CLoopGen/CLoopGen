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
    for (size_t j = 1; j < N; j++) {
        size_t i = j * stride;
        for (size_t k = 1; k < stride; k++) {
            size_t idx = i + k;
            status |= (data[idx] != (12345. + idx));
        }
    }
}
