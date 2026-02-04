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
    // Variant 2: Consecutive access by flattening the diagonal into a temporary array (simulated consecutive pattern)
    double temp_diag[C->m];
    double **me = C->me;

    // Extract diagonal elements consecutively
    for (i = 0; i < C->m; i++) {
        temp_diag[i] = me[i][i];
    }

    // Operate on the consecutive array
    for (i = 0; i < C->m; i++) {
        temp_diag[i] -= 1.0;
    }

    // Write back to original diagonal locations
    for (i = 0; i < C->m; i++) {
        me[i][i] = temp_diag[i];
    }
}
