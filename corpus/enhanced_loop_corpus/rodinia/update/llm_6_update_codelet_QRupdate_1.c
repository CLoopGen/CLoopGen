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

extern MAT *R;
extern VEC *v;
extern int j;
extern double temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double *restrict row = R->me[0];
    const double *restrict vec = v->ve;
    double temp_val = temp;
    for (int j = 0; j < R->n; j++) {
        row[j] = row[j] + temp_val * vec[j];
    }
}
