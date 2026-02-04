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
    u_int total_ops = new->m * new->n;
    u_int idx = 0;
    for (i = 0; i < total_ops; i++) {
        u_int row = i / new->n;
        u_int col = i % new->n;
        if (col == 0 && row < new->m) {
            new->me[row] = (old->me[row + row1]) + col1;
        }
    }
}
