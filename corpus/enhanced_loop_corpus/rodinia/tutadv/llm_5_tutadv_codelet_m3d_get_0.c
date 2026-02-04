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
    k = 0;
    for (i = 0; i < l && k < mat->max_l * mat->max_m; i++) {
        for (j = 0; j < m && k < mat->max_l * mat->max_m; j++) {
            mat->me2d[k] = &mat->base[(i * m + j) * n];
            k++;
        }
    }
}
