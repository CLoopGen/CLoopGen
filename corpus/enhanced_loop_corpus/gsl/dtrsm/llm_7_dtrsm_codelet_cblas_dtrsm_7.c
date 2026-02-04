#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double alpha;
extern double *B;
extern  int ldb;
extern int i;
extern int j;
extern int n1;
extern int n2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int ii, jj;
    // Tiled (blocked) version to alter data access pattern and remove immediate loop-carried dependencies
    // Using local accumulations to eliminate direct sequential dependencies across iterations
    const int block_size = 16;
    for (ii = 0; ii < n1; ii += block_size) {
        for (jj = 0; jj < n2; jj += block_size) {
            int i_end = (ii + block_size < n1) ? ii + block_size : n1;
            int j_end = (jj + block_size < n2) ? jj + block_size : n2;
            for (i = ii; i < i_end; i++) {
                for (j = jj; j < j_end; j++) {
                    B[ldb * i + j] *= alpha; // Independent operations within tile – no loop-carried deps
                }
            }
        }
    }
}
