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

extern int i;
extern MAT *R1;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int k;
    for (j = 0; j < i * 2; j += 2) {
        for (k = 0; k < 5; k++) {
            R1->me[i + 1][(j + k) % R1->max_n] += (double)(k * 2);
        }
    }
}
