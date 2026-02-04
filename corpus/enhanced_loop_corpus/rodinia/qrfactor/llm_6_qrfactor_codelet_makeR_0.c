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
    u_int temp_i, temp_j;
    double **rout_me = Rout->me;
    u_int qr_m = QR->m;
    for (temp_i = 1; temp_i < qr_m; temp_i++) {
        for (temp_j = 0; temp_j < QR->n && temp_j < temp_i; temp_j++) {
            rout_me[temp_i][temp_j] = 0.;
        }
    }
}
