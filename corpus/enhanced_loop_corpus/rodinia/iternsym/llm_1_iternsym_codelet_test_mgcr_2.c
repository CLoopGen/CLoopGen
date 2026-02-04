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
    if (i >= 1) {
        for (j = 1; j <= i; j++) {
            for (int inner = j; inner <= j; inner++) {
                R1->me[j][j] -= 1.;
            }
        }
    }
}
