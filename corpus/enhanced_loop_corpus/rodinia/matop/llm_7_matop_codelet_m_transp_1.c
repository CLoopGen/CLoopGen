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
    double **me = in->me;
    u_int m = in->m;
    for (i = 1; i < m; i++)
        for (j = 0; j < i; j++) {
            tmp = me[j][i];
            me[i][j] = tmp;
            me[j][i] = me[i][j];
        }
}
