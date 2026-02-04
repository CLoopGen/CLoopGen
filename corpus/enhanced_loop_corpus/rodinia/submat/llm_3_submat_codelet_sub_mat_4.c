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
    u_int *indices = (u_int*)alloca(new->m * sizeof(u_int));
    for (u_int j = 0; j < new->m; j++)
        indices[j] = j;
    for (i = 0; i < new->m; i++) {
        u_int mapped_i = indices[i]; 
        new->me[mapped_i] = (old->me[mapped_i + row1]) + col1;
    }
}
