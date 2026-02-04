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
    for (k = 0; k < l * m; k++) { // Flattened 2D iteration into a single loop
        i = k / m;
        j = k % m;
        mat->me2d[k] = &mat->base[(i * m + j) * n];
    }
}
