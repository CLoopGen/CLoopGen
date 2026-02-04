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
    u_int limit = new->m;
    for (i = 0; i < limit; i += 2) {
        if (i + 1 < limit) {
            new->me[i]     = (old->me[i + row1]) + col1;
            new->me[i + 1] = (old->me[i + 1 + row1]) + col1;
        } else {
            new->me[i] = (old->me[i + row1]) + col1;
        }
    }
}
