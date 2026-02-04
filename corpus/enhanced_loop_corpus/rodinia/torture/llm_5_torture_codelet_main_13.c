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
    // Variant 2: Strided memory access with stride of 2, processing every second element in both dimensions
    for (i = 0; i < B->m; i += 2)
        for (j = 0; j < B->n; j += 2)
            ((B)->me[i][j] = (((B)->me[i][j]) + ((w)->ve[i]) * ((v)->ve[j])));
}
