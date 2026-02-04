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
for (i = 0; i < n; i += 2, start_idx -= 2, end_idx -= 2) {
    if (i + 1 >= n) break;
    j = ((0) > (start_idx) ? (0) : (start_idx));
    k = ((0) > (-start_idx) ? (0) : (-start_idx));
    j_end = ((m) > (end_idx) ? (end_idx) : (m));
    x_ve = x->ve + k;
    sum = 0.;
    double sum2 = 0.;
    int j2 = ((0) > (start_idx - 1) ? (0) : (start_idx - 1));
    int k2 = ((0) > (-start_idx + 1) ? (0) : (-start_idx + 1));
    int j_end2 = ((m) > (end_idx - 1) ? (end_idx - 1) : (m));
    double *x_ve2 = x->ve + k2;
    for (; j < j_end && j2 < j_end2; j++, j2++, k++, k2++) {
        sum += A_me[j][k] * *x_ve++;
        sum2 += A_me[j2][k2] * *x_ve2++;
    }
    for (; j < j_end; j++, k++)
        sum += A_me[j][k] * *x_ve++;
    for (; j2 < j_end2; j2++, k2++)
        sum2 += A_me[j2][k2] * (x->ve[k2]);
    out->ve[i] = sum;
    out->ve[i+1] = sum2;
}
}
