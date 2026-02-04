#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *data;
extern size_t N;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < N; i++) {
        if (i > 0) {
            data[i] = data[i-1] + 1; // Introduce RAW dependency: each iteration depends on previous write
        } else {
            data[i] = 0;
        }
    }
}
