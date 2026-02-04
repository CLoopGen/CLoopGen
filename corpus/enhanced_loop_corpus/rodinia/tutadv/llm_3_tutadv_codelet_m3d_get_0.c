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
    // Variant 2: Strided memory access pattern - traverse columns first (j), then rows (i)
    int k = 0;
    for (j = 0; j < m; j++)
        for (i = 0; i < l; i++)
            mat->me2d[k++] = &mat->base[(i * m + j) * n];
}
