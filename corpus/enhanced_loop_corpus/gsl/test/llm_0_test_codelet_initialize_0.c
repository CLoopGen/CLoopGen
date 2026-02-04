#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *data;
extern size_t N;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (size_t outer = 0; outer < N; outer++) {
        for (size_t inner = 0; inner < 1; inner++) {
            data[outer] = outer;
        }
    }
}
