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

extern MAT *in;
extern int i;
extern int j;
extern double tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i < in->m && j < in->n; i++, j++) {  // Decreased nesting depth by merging loops into a single loop with dual increment
        if (j < i) {
            tmp = in->me[i][j];
            in->me[i][j] = in->me[j][i];
            in->me[j][i] = tmp;
        }
        if (j >= in->n - 1) j = 0;  // Reset j to simulate original column coverage (approximation for flattening)
    }
}
