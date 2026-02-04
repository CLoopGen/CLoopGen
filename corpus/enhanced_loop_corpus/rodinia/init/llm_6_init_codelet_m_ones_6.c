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

extern MAT *A;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double **me = A->me;
    u_int m = A->m;
    u_int n = A->n;
    for (i = 0; i < m; i++) {
        double *row = me[i];
        for (j = 0; j < n; j++) {
            row[j] = 1.0;
        }
    }
}
