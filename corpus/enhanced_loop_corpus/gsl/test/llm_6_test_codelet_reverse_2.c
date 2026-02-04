#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *data;
extern size_t N;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < N / 2; i++) {
        size_t j = N - i - 1;
        double tmp1 = data[i];
        double tmp2 = data[j];
        data[i] = tmp2;
        data[j] = tmp1;
    }
}
