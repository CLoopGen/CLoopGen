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
    u_int i_start = 1;
    u_int stride = 2;
    for (i = i_start; i < QR->m; i += stride) {
        for (j = 0; j < QR->n && j < i; j++) {
            Rout->me[i][j] = 0.0;
            if (i + 1 < QR->m) {
                Rout->me[i+1][j] = 0.0;
            }
        }
    }
    for (u_int leftover = (QR->m - 1) & 1 ? 0 : 1; leftover < QR->n && (QR->m - 1) >= i_start; leftover++) {
        Rout->me[QR->m - 1][leftover] = 0.0;
    }
}
