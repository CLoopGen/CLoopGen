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
    for (i = 0; i < n; i++, start_idx--, end_idx--) {
        j = ((0) > (start_idx) ? (0) : (start_idx));
        k = ((0) > (-start_idx) ? (0) : (-start_idx));
        j_end = ((m) > (end_idx) ? (end_idx) : (m));
        x_ve = x->ve + k;
        sum = 0.;
        if (j < j_end) {
            for (int iter = j; iter < j_end; iter++, k++) {
                sum += A_me[iter][k] * x_ve[iter - j];
            }
        }
        out->ve[i] = sum;
    }
}
