#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct AVComplexInt32 {
    int32_t re;
    int32_t im;
} AVComplexInt32;

typedef AVComplexInt32 FFTComplex;

struct AVTXContext {
    int n;
    int m;
    int inv;
    int type;
    FFTComplex *exptab;
    FFTComplex *tmp;
    int *pfatab;
    int *revtab;
};

typedef struct AVTXContext AVTXContext;

AVTXContext *s;
int m;
int *out_map;
FFTComplex *out;

void init_vars() {
    m = 1 << 20; // 1M elements, scales 3*m to ~3M accesses, suitable for ~0.01 sec

    s = (AVTXContext*)calloc(1, sizeof(AVTXContext));
    if (!s) exit(1);

    s->m = m;
    s->n = 3 * m;

    s->tmp = (FFTComplex*)calloc(3 * m, sizeof(FFTComplex));
    if (!s->tmp) exit(1);

    out_map = (int*)malloc(3 * m * sizeof(int));
    if (!out_map) exit(1);

    for (int i = 0; i < 3 * m; i++) {
        out_map[i] = i % (3 * m);
        s->tmp[i].re = (int32_t)(i * 789);
        s->tmp[i].im = (int32_t)(i * 987);
    }

    out = (FFTComplex*)malloc(3 * m * sizeof(FFTComplex));
    if (!out) exit(1);
}