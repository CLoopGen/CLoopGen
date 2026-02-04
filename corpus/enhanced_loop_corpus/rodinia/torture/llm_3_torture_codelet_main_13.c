#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    u_int dim;
    u_int max_dim;
    double *ve;
} VEC;

typedef struct {
    u_int m;
    u_int n;
    u_int max_m;
    u_int max_n;
    u_int max_size;
    double **me;
    double *base;
} MAT;

extern VEC *v;
extern VEC *w;
extern MAT *B;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < B->m; i++)
        ((B)->me[i][0] = (((B)->me[i][0]) + ((w)->ve[i]) * ((v)->ve[0])));
    for (j = 1; j < B->n; j++)
        for (i = 0; i < B->m; i++)
            ((B)->me[i][j] = (((B)->me[i][j]) + ((w)->ve[i]) * ((v)->ve[j])));
}
