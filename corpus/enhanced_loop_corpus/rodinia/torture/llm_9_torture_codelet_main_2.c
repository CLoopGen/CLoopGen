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
    int limit = (C->m > 0) ? C->m - 1 : 0;
    for (i = 0; i < limit; i += 2) {
        if (i + 1 < C->m) {
            (C)->me[i][i] = (C)->me[i][i] - 1.0;
            (C)->me[i+1][i+1] = (C)->me[i+1][i+1] - 1.0;
        } else {
            (C)->me[i][i] = (C)->me[i][i] - 1.0;
        }
    }
}
