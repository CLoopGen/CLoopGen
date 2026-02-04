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
    u_int stride = 2;
    u_int limit = (new->m + stride - 1) / stride;
    for (i = 0; i < limit; i++) {
        u_int src_idx = i * stride + row1;
        u_int dst_idx = i * stride;
        if (dst_idx < new->m)
            new->me[dst_idx] = old->me[src_idx] + col1;
        if (dst_idx + 1 < new->m && (dst_idx + 1) < new->m)
            new->me[dst_idx + 1] = old->me[src_idx + 1] + col1;
    }
}
