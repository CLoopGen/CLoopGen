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
    int j;
    s1 = 0.0;
    for (i = 0; i < C->m && i < C->n; i++) {
        double diag = (C)->me[i][i];
        s1 += diag * diag;  // Increased arithmetic intensity: square each diagonal element
        for (j = 1; j < 4; j++) {  // Add small inner loop to increase computation per iteration
            s1 += ((C)->me[i][(i+j) % C->n]) * 0.1;  // Slight off-diagonal contribution
        }
    }
}
