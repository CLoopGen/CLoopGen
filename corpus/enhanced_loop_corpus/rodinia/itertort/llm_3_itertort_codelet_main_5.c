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

extern int j;
extern MAT *Q;
extern MAT *H1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive access via flattened index and pointer arithmetic
    // Simulate consecutive memory writes by accessing through a linearized view
    double *flat_base = H1->base;
    int max_diag = (Q->m < H1->max_n) ? Q->m : H1->max_n;
    ptrdiff_t row_skip = H1->max_n; // distance between row starts
    for (int idx = 0; idx < max_diag; idx++) {
        double *element_addr = flat_base + (idx * row_skip) + idx;
        *element_addr -= 1.;
    }
}
