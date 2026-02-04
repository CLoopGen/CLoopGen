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
extern int size;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int j;
for (i = 0; i < size; i++)
    for (j = 0; j < size; j++)
        if (i == j)
            A->me[i][j] = 1.;
        else
            A->me[i][j] = 0.;
}
