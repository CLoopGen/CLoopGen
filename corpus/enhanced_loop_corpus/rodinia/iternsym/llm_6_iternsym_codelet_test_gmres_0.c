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

extern int i;
extern MAT *R1;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double **me = R1->me;
    int local_i = i;
    for (j = 0; j < local_i; j++) {
        me[local_i + 1][j] = 0.;
        me[local_i + 1][j + 1] = me[local_i + 1][j]; // Introduce RAW dependency: current iteration depends on previous write
    }
}
