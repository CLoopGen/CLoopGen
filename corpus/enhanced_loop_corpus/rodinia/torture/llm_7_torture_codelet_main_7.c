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
extern double s1;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double local_sum = 0.0;
    int limit = (C->m < C->n) ? C->m : C->n;
    for (i = 0; i < limit; i++) {
        local_sum += (C->me[i][i]);
    }
    s1 += local_sum;
}
