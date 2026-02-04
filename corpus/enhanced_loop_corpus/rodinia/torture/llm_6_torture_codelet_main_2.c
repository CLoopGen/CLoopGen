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
    double **me = C->me;
    u_int m = C->m;
    for (i = 0; i < m; i++) {
        double temp = me[i][i];
        temp = temp - 1.0;
        me[i][i] = temp;
    }
}
