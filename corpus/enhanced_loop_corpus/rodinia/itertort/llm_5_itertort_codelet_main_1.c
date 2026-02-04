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

extern int kk;
extern int j;
extern MAT *H1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 0; j < kk; j++) {
        if (H1->me[j] != NULL) {
            H1->me[j][j] -= 1.;
        }
    }
}
