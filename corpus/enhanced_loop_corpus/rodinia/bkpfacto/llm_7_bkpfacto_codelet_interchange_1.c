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
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double **me = (A)->me;
    double temp_store[2] = {0};
    int idx;

    for (k = j + 1; k < n; k++) {
        idx = (k - (j + 1)) % 2;
        if (idx == 0) {
            temp_store[idx] = me[j][k];
            me[j][k] = me[i][k];
        } else {
            me[i][k - 1] = temp_store[0];
            temp_store[idx] = me[j][k];
            me[j][k] = me[i][k];
        }
    }

    if ((n - j - 1) % 2 == 1) {
        idx = (n - j - 2) % 2;
        me[i][n - 1] = temp_store[idx];
    } else if (n > j + 1) {
        me[i][n - 1] = temp_store[1];
    }
}
