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
    for (j = 0; j < mat->n; j++) {
        if (j % 2 == 0) {
            temp = c * ((out)->me[i][j]) + s * ((out)->me[k][j]);
            ((out)->me[k][j] = (-s * ((out)->me[i][j]) + c * ((out)->me[k][j])));
            ((out)->me[i][j] = (temp));
        } else {
            double *row_i = (out)->me[i];
            double *row_k = (out)->me[k];
            temp = c * row_i[j] + s * row_k[j];
            row_k[j] = -s * row_i[j] + c * row_k[j];
            row_i[j] = temp;
        }
    }
}
