#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *data;
extern size_t N;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    for (i = 0; i < N / 2; i += 2) {
        size_t j = N - i - 1;
        size_t j_next = N - i - 2;
        // Process two elements at a time with stride
        if (i + 1 < N / 2) {
            double tmp1 = data[i];
            data[i] = data[j];
            data[j] = tmp1;

            double tmp2 = data[i + 1];
            data[i + 1] = data[j_next];
            data[j_next] = tmp2;
        } else {
            // Handle last element if N is odd and i reaches boundary
            double tmp = data[i];
            data[i] = data[j];
            data[j] = tmp;
        }
    }
}
