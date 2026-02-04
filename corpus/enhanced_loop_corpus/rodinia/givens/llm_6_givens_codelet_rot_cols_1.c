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
    double temp_c, temp_s;
    temp_c = c;
    temp_s = s;
    for (j = 0; j < mat->m; j++) {
        double out_j_i = (out)->me[j][i];
        double out_j_k = (out)->me[j][k];
        temp = temp_c * out_j_i + temp_s * out_j_k;
        (out)->me[j][k] = (-temp_s * out_j_i + temp_c * out_j_k);
        (out)->me[j][i] = temp;
    }
}
