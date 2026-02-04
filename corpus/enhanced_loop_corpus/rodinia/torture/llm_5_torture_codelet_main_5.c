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
    for (i = 0; i < C->m && i < C->n; i++) {
        double temp = (C)->me[i][i];
        if (temp > 0.0) {
            (C)->me[i][i] = temp - 3.71;
        }
    }
}
