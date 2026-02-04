#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  double *X;
extern  int incX;
extern double *Y;
extern  int incY;
extern int i;
extern int ix;
extern int iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i_outer, i_inner;
    const int block_size = 2;
    int num_blocks = (N + block_size - 1) / block_size;

    for (i_outer = 0; i_outer < num_blocks; i_outer++) {
        for (i_inner = 0; i_inner < block_size; i_inner++) {
            int i = i_outer * block_size + i_inner;
            if (i < N) {
                Y[iy] = X[ix];
                ix += incX;
                iy += incY;
            }
        }
    }
}
