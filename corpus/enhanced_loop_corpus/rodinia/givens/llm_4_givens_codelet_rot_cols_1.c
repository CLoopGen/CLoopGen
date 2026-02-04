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

extern MAT *mat;
extern MAT *out;
extern u_int i;
extern u_int k;
extern double c;
extern double s;
extern u_int j;
extern double temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 0; j < mat->m; j++) {
        if (!((out)->me[j][i] == 0.0 && (out)->me[j][k] == 0.0)) {
            temp = c * ((out)->me[j][i]) + s * ((out)->me[j][k]);
            ((out)->me[j][k] = (-s * ((out)->me[j][i]) + c * ((out)->me[j][k])));
            ((out)->me[j][i] = (temp));
        }
    }
}
