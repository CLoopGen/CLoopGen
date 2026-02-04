#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *dfdy;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (size_t outer = 0; outer < 15; outer++) {
        for (size_t inner = 0; inner < 15; inner++) {
            dfdy[outer * 15 + inner] = 0.;
        }
    }
}
