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
    for (i = 0; i < N && j < tda; i++, j++) {
        status |= (data[i * tda + j] != (12345. + (i * tda + j)));
    }
}
