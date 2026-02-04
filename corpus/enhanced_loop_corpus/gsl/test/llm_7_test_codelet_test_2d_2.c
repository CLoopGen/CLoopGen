#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t N;
extern size_t tda;
extern size_t i;
extern double *data;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double temp = 12345.0;
    for (i = 0; i < N * tda; i++) {
        temp += 1.0;
        data[i] = temp;
    }
}
