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
extern int l;
extern int n;
extern int n1;
extern int lb;
extern int ub;
extern double **bmat;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (j = 0; j < n; j++)
    for (i = ((n1) > (j + lb) ? (j + lb) : (n1)) , l = lb + j - i; i >= ((0) > (j - ub) ? (0) : (j - ub)); i-- , l++)
        A->me[i][j] = bmat[l][j];

}
