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

extern MAT *old;
extern MAT *new;
extern u_int row1;
extern u_int col1;
extern u_int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (new->m > 0) {
        new->me[0] = (old->me[0 + row1]) + col1;
        for (i = 1; i < new->m; i++) {
            new->me[i] = new->me[i - 1] + (old->me[i + row1] - old->me[i + row1 - 1]);
        }
    }
}
