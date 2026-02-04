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
    for (i = 0; i < N; i++) {
        if (src[i] != 0.0) {
            dest[i] = src[i];
        } else {
            dest[i] = 0.0;
        }
    }
}
