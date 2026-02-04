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

extern MAT *C;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (C == NULL || C->me == NULL || C->m == 0) return;
    for (i = 0; i < C->m; i++) {
        if (i >= C->max_m || i >= C->max_n) continue;
        double *row = C->me[i];
        row[i] = row[i] - 1.0;
    }
}
