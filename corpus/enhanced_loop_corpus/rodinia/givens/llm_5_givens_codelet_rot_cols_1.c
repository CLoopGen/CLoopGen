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
    u_int limit = mat->m;
    for (j = 0; j < limit; j++) {
        double val_i = (out)->me[j][i];
        double val_k = (out)->me[j][k];
        if (j % 2 == 0) {
            temp = c * val_i + s * val_k;
            (out)->me[j][k] = -s * val_i + c * val_k;
            (out)->me[j][i] = temp;
        } else {
            (out)->me[j][i] = c * val_i + s * val_k;
            (out)->me[j][k] = -s * val_i + c * val_k;
        }
    }
}
