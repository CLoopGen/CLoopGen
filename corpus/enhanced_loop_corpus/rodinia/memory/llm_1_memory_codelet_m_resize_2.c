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

extern MAT *A;
extern int new_m;
extern int new_n;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (new_m > 0) {
        i = 0;
        for (; i < new_m; ) {
            A->me[i] = &(A->base[i * new_n]);
            i++;
        }
    }
}
