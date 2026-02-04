#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t N;
extern size_t tda;
extern size_t i;
extern size_t j;
extern double *data;
extern int status;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t temp_index;
    for (i = 0; i < N; i++) {
        temp_index = i * tda;
        for (j = N; j < tda; j++) {
            size_t idx = temp_index + j;
            status |= (data[idx] != (12345. + idx));
        }
    }
}
