#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    u_int m;
    u_int n;
    u_int max_m;
    u_int max_n;
    u_int max_size;
    double **me;
    double *base;
} MAT;

extern int m;
extern int n;
extern MAT *matrix;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    u_int temp_m = m;
    for (i = 0; i < temp_m; i++) {
        double *row_start = &(matrix->base[i * n]);
        matrix->me[i] = row_start;
    }
}
