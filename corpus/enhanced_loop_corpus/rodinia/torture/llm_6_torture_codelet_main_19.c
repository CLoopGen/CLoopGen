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

extern MAT *D;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double *base = D->base;
    u_int m = D->m;
    for (i = 0; i < m; i++) {
        ptrdiff_t offset = i * (m + 1);
        base[offset] = base[offset] - 1.0;
    }
}
