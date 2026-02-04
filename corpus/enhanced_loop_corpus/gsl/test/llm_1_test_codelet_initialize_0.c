#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *data;
extern size_t N;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (N > 0) {
        for (size_t i = 0; i < N; i += 2) {
            data[i] = i;
            if (i + 1 < N) {
                data[i + 1] = i + 1;
            }
        }
    }
}
