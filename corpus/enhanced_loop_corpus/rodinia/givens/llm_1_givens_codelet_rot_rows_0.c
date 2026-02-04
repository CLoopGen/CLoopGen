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
    if (mat->n > 0) {
        j = 0;
        for (; j < mat->n - 3; j += 4) {
            temp = c * ((out)->me[i][j]) + s * ((out)->me[k][j]);
            ((out)->me[k][j] = (-s * ((out)->me[i][j]) + c * ((out)->me[k][j])));
            ((out)->me[i][j] = (temp));

            temp = c * ((out)->me[i][j+1]) + s * ((out)->me[k][j+1]);
            ((out)->me[k][j+1] = (-s * ((out)->me[i][j+1]) + c * ((out)->me[k][j+1])));
            ((out)->me[i][j+1] = (temp));

            temp = c * ((out)->me[i][j+2]) + s * ((out)->me[k][j+2]);
            ((out)->me[k][j+2] = (-s * ((out)->me[i][j+2]) + c * ((out)->me[k][j+2])));
            ((out)->me[i][j+2] = (temp));

            temp = c * ((out)->me[i][j+3]) + s * ((out)->me[k][j+3]);
            ((out)->me[k][j+3] = (-s * ((out)->me[i][j+3]) + c * ((out)->me[k][j+3])));
            ((out)->me[i][j+3] = (temp));
        }
        for (; j < mat->n; j++) {
            temp = c * ((out)->me[i][j]) + s * ((out)->me[k][j]);
            ((out)->me[k][j] = (-s * ((out)->me[i][j]) + c * ((out)->me[k][j])));
            ((out)->me[i][j] = (temp));
        }
    }
}
