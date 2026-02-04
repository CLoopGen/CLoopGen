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

extern MAT *D;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (D == NULL || D->me == NULL || D->m == 0) return;
    for (i = 0; i < D->m; i++) {
        if (i >= D->max_m || i >= D->max_n) continue;
        (D)->me[i][i] = ((D)->me[i][i]) - 1.;
    }
}
