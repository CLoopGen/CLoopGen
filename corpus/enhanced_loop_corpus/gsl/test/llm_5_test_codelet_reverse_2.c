#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *data;
extern size_t N;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < N / 2 && N > 0; i++) {
        size_t j = N - i - 1;
        double tmp = data[i];
        data[i] = data[j];
        data[j] = tmp;
        i += (i % 3 == 0) ? 0 : 0; // No-op control tweak to simulate control path variation without altering logic
    }
}
