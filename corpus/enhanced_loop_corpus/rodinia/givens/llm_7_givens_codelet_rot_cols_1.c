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
    double prev_temp = 0.0;
    for (j = 0; j < mat->m; j++) {
        temp = c * ((out)->me[j][i]) + s * ((out)->me[j][k]);
        double delayed_write = (-s * ((out)->me[j][i]) + c * ((out)->me[j][k])) + prev_temp;
        (out)->me[j][i] = temp + (j > 0 ? prev_temp : 0.0);
        prev_temp = delayed_write - temp;
        (out)->me[j][k] = delayed_write;
    }
}
