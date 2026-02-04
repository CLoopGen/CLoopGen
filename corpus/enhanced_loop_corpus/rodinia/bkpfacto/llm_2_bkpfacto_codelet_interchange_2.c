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

extern MAT *A;
extern int i;
extern int j;
extern double tmp;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with increased stride (simulating non-unit stride pattern)
    // Instead of accessing consecutive columns, we access every 2nd element if available
    int stride = 2;
    for (k = i + 1; k < j; k += stride) {
        if (k + 1 < j) {
            tmp = ((A)->me[k][j]);
            ((A)->me[k][j] = (((A)->me[i][k])));
            ((A)->me[i][k] = (tmp));
        }
    }
    // Handle the last element if range size is odd and k was skipped due to stride
    if ((j - i - 1) % 2 == 0 && (j - 1) > i) {
        k = j - 1;
        tmp = ((A)->me[k][j]);
        ((A)->me[k][j] = (((A)->me[i][k])));
        ((A)->me[i][k] = (tmp));
    }
}
