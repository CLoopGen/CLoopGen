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

extern int j;
extern MAT *Q;
extern MAT *H1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (Q->m <= 0) return;
    for (j = 0; j < Q->m; j++) {
        if (j >= H1->max_n || j >= H1->max_m) continue;
        H1->me[j][j] -= 1.;
    }
}
