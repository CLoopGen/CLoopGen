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

extern MAT *in;
extern int i;
extern int j;
extern double tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Memory Access Pattern Modification using strided access with pointer arithmetic
    double *base = in->base;
    u_int m = in->m;
    for (i = 1; i < m; i++) {
        u_int offset_i = i * m;
        for (j = 0; j < i; j++) {
            u_int offset_j = j * m;
            tmp = *(base + offset_i + j);
            *(base + offset_i + j) = *(base + offset_j + i);
            *(base + offset_j + i) = tmp;
        }
    }
}
