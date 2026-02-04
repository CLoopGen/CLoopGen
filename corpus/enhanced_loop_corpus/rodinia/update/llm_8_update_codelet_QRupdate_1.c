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
    int j;
    double *me_row = R->me[0];
    double *ve = v->ve;
    for (j = 0; j < R->n; j += 2) {
        if (j + 1 < R->n) {
            me_row[j]     += temp * ve[j];
            me_row[j + 1] += temp * ve[j + 1];
        } else {
            me_row[j] += temp * ve[j];
        }
    }
}
