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
    double expected;
    size_t idx;
    for (i = 0; i < N; i++) {
        for (j = N; j < tda; j++) {
            idx = i * tda + j;
            expected = 12345.0 + idx;
            if (data[idx] != expected) {
                status = 1;
            }
        }
    }
    // Introduce loop-independent dependency: final status depends on all iterations,
    // but no loop-carried dependency in computation; reduces redundant status updates.
}
