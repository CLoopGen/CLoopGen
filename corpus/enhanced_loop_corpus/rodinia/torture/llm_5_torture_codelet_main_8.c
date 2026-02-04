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
    u_int limit = (D->m < D->max_size) ? D->m : D->max_size;
    for (i = 0; i < limit; i++) {
        if (((D)->me[i]) != NULL)
            (D)->me[i][i] = ((D)->me[i][i]) - 1.;
    }
}
