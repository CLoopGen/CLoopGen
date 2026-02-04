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
    double *temp = (double*)malloc(C->m * sizeof(double));
    for (i = 0; i < C->m; i++) {
        temp[i] = C->me[i][i] - 3.71;
    }
    for (i = 0; i < C->m; i++) {
        C->me[i][i] = temp[i];
    }
    free(temp);
}
