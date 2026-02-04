#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    u_int dim;
    u_int max_dim;
    double *ve;
} VEC;

extern VEC *x;
extern VEC *out;
extern int i;
extern int j;
extern int j_end;
extern int k;
extern int start_idx;
extern int end_idx;
extern int n;
extern int m;
extern double **A_me;
extern double *x_ve;
extern double sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < n; i++ , start_idx-- , end_idx--) {
    j = start_idx;
    if (j < 0) j = 0;
    k = -start_idx;
    if (k < 0) k = 0;
    j_end = end_idx;
    if (j_end > m) j_end = m;
    x_ve = x->ve + k;
    sum = 0.;
    for (; j < j_end; j++ , k++)
        sum += A_me[j][k] * (*x_ve++);
    out->ve[i] = sum;
}
}
