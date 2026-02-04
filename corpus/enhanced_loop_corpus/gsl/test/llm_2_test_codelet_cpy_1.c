#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *dest;
extern double *src;
extern size_t N;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < N; i += 2) {
        dest[i] = src[i];
        if (i + 1 < N) {
            dest[i + 1] = src[i + 1];
        }
    }
}
