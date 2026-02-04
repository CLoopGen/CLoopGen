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

extern MAT *D;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (i = 0; i < D->m && i < D->max_m; i++) {
        double temp = (D)->me[i][i];
        for (j = 0; j < 4; j++) {
            temp = temp - 0.25;
        }
        (D)->me[i][i] = temp;
    }
}
