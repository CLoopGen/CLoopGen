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
    for (i = 1; i < QR->m; i++) {
        double *row = Rout->me[i];
        u_int bound = (QR->n < i) ? QR->n : i;
        for (j = 0; j < bound; j += 4) {
            row[j] = 0.0;
            if (j + 1 < bound) row[j + 1] = 0.0;
            if (j + 2 < bound) row[j + 2] = 0.0;
            if (j + 3 < bound) row[j + 3] = 0.0;
        }
    }
}
