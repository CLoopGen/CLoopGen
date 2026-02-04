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

ZMAT *H;
int i;
int j;
int limit;

void init_vars() {
    limit = 1024; // Controls outer loop: ~1023*1024/2 ≈ 500K iterations, reasonable for ~0.01s

    H = (ZMAT*)calloc(1, sizeof(ZMAT));
    H->m = limit;
    H->n = limit;
    H->max_m = limit;
    H->max_n = limit;
    H->max_size = limit * limit;

    H->base = (complex*)calloc(H->max_size, sizeof(complex));

    H->me = (complex**)calloc(H->max_m, sizeof(complex*));
    for (u_int row = 0; row < H->max_m; ++row) {
        H->me[row] = &(H->base[row * H->max_n]);
    }
}