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

extern MAT *Hout;
extern int i;
extern int j;
extern int limit;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int i_start = 1;
int step = 2;
for (i = i_start; i < limit; i += step)
    for (j = 0; j < (i - 1); j++)
        ((Hout)->me[i][j] = (0.)),
        ((Hout)->me[i-1][j] = (0.));
}
