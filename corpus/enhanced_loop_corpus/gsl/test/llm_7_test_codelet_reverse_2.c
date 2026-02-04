#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *data;
extern size_t N;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (N > 0 && (N & 1) == 0) {
        for (i = 0; i < N / 2; i += 2) {
            size_t j1 = N - i - 1;
            size_t j2 = N - i - 2;
            double tmp1 = data[i];
            double tmp2 = data[i + 1];
            data[i] = data[j1];
            data[i + 1] = data[j2];
            data[j1] = tmp1;
            data[j2] = tmp2;
        }
    } else {
        for (i = 0; i < N / 2; i++) {
            size_t j = N - i - 1;
            double tmp = data[i];
            data[i] = data[j];
            data[j] = tmp;
        }
    }
}
