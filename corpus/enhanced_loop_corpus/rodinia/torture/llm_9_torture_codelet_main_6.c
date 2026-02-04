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
    if (C->m > 0) {
        (C)->me[0][0] = ((C)->me[0][0]) - 1.;
        for (i = 2; i < C->m; i += 2) {
            (C)->me[i][i] = ((C)->me[i][i]) - 1.;
            if (i + 1 < C->m) {
                (C)->me[i+1][i+1] = ((C)->me[i+1][i+1]) - 1.;
            }
        }
    }
}
