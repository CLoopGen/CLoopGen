#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef double bench_real;

typedef bench_real R;

typedef enum {
    R2R_R2HC,
    R2R_HC2R,
    R2R_DHT,
    R2R_REDFT00,
    R2R_REDFT01,
    R2R_REDFT10,
    R2R_REDFT11,
    R2R_RODFT00,
    R2R_RODFT01,
    R2R_RODFT10,
    R2R_RODFT11
} r2r_kind_t;

R *b;
R *a;
int n;
int nb;
int na;
r2r_kind_t k;
int isL0;
int isL1;
int isR0;
int isR1;
int i;
int ib;
int ia;

void init_vars() {
    na = 64;
    n = 512;
    nb = 64;

    size_t total_elements = (size_t)nb * n * na;
    size_t bytes = total_elements * sizeof(R);

    a = (R*)aligned_alloc(32, bytes);
    b = (R*)aligned_alloc(32, bytes);

    for (size_t idx = 0; idx < total_elements; ++idx) {
        a[idx] = (R)(rand() % 1000) / 100.0;
        b[idx] = 0.0;
    }

    k = R2R_R2HC;

    isL0 = 0;
    isL1 = 0;
    isR0 = 0;
    isR1 = 0;
}