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

MAT *QR;
MAT *Rout;
u_int i;
u_int j;

void init_vars() {
    QR = (MAT*)malloc(sizeof(MAT));
    Rout = (MAT*)malloc(sizeof(MAT));

    QR->m = 5000;
    QR->n = 5000;
    QR->max_m = QR->m;
    QR->max_n = QR->n;
    QR->max_size = QR->m * QR->n;
    QR->base = (double*)calloc(QR->max_size, sizeof(double));
    QR->me = (double**)malloc(QR->m * sizeof(double*));
    for (u_int idx = 0; idx < QR->m; idx++) {
        QR->me[idx] = QR->base + idx * QR->n;
    }

    Rout->m = QR->m;
    Rout->n = QR->n;
    Rout->max_m = QR->m;
    Rout->max_n = QR->n;
    Rout->max_size = QR->m * QR->n;
    Rout->base = (double*)calloc(Rout->max_size, sizeof(double));
    Rout->me = (double**)malloc(Rout->m * sizeof(double*));
    for (u_int idx = 0; idx < Rout->m; idx++) {
        Rout->me[idx] = Rout->base + idx * Rout->n;
    }
}