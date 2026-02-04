#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct {
    double re;
    double im;
} complex;

typedef struct {
    u_int m;
    u_int n;
    u_int max_m;
    u_int max_n;
    u_int max_size;
    complex *base;
    complex **me;
} ZMAT;

ZMAT *QR;
ZMAT *Rout;
u_int i;
u_int j;

void init_vars() {
    QR = (ZMAT*)calloc(1, sizeof(ZMAT));
    Rout = (ZMAT*)calloc(1, sizeof(ZMAT));

    QR->m = 5000;
    QR->n = 5000;
    QR->max_m = QR->m;
    QR->max_n = QR->n;
    QR->max_size = QR->m * QR->n;

    Rout->m = QR->m;
    Rout->n = QR->n;
    Rout->max_m = Rout->m;
    Rout->max_n = Rout->n;
    Rout->max_size = Rout->m * Rout->n;

    Rout->base = (complex*)calloc(Rout->max_size, sizeof(complex));
    Rout->me = (complex**)calloc(Rout->m, sizeof(complex*));
    for (u_int idx = 0; idx < Rout->m; idx++) {
        Rout->me[idx] = &(Rout->base[idx * Rout->n]);
    }
}