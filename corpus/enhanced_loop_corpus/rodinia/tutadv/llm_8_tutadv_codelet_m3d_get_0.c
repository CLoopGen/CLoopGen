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
    for (i = 0, k = 0; i < l; i++) {
        for (j = 0; j < m; j++) {
            int idx = (i * m + j) * n;
            double *ptr = &mat->base[idx];
            mat->me2d[k++] = ptr;
            // Additional arithmetic to increase computational intensity
            idx += n - 1;
            ptr = &mat->base[idx];
        }
    }
}
