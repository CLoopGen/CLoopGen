#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    int l;
    int m;
    int n;
    int max_l;
    int max_m;
    int max_n;
    double ***me;
    double *base;
    double **me2d;
} MAT3D;

extern int l;
extern int m;
extern int n;
extern MAT3D *mat;
extern int i;
extern int j;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access pattern using a single loop with stride calculation
    int idx = 0;
    for (i = 0; i < l * m; i++) {
        int row = i / m;
        int col = i % m;
        mat->me2d[idx++] = &mat->base[(row * m + col) * n];
    }
}
