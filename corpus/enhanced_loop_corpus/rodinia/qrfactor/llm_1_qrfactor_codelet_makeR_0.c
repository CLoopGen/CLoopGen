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

extern MAT *QR;
extern MAT *Rout;
extern u_int i;
extern u_int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (QR->m > 1) {
        i = 1;
        do {
            for (j = 0; j < QR->n && j < i; j++) {
                Rout->me[i][j] = 0.;
            }
            i++;
        } while (i < QR->m);
    }
}
