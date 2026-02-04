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

typedef struct {
    u_int dim;
    u_int max_dim;
    double *ve;
} VEC;

extern MAT *out;
extern VEC *a;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int step = 2;
    for (j = 0; j < out->n; j += step) {
        if (j < out->max_n && j < out->max_m) {
            out->me[j][j] = a->ve[0];
            if (j + 1 < out->n) {
                out->me[j+1][j+1] = a->ve[0];
            }
        }
    }
}
