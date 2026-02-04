#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int nmin;
extern  int nmax;
extern double *result_array;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int outer;
    int range = nmax - nmin + 1;
    int block_size = 16;
    for (outer = 0; outer < range; outer += block_size) {
        int inner;
        for (inner = outer; inner < outer + block_size && inner <= nmax - nmin; inner++)
            result_array[inner] = 0.;
    }
}
