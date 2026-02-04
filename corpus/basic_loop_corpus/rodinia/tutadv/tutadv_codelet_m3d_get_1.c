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
extern MAT3D *mat;
extern int i;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (i = 0; i < l; i++)
    mat->me[i] = &mat->me2d[i * m];

}
