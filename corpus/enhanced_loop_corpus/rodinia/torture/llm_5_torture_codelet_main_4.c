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
    u_int size = C ? C->m : 0;
    u_int limit = (size < C->max_size) ? size : C->max_size;
    for (i = 0; i < limit; i++) {
        if (C->me[i] != NULL)
            C->me[i][i] -= 1.0;
        else
            break;
    }
}
