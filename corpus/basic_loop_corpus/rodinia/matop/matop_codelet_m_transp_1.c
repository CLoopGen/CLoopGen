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
for (i = 1; i < in->m; i++)
    for (j = 0; j < i; j++) {
        tmp = in->me[i][j];
        in->me[i][j] = in->me[j][i];
        in->me[j][i] = tmp;
    }

}
