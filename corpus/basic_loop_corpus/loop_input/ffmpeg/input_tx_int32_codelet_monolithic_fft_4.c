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
FFTComplex *in;
FFTComplex *out;
int m;

void init_vars() {
    m = 1 << 17; // 131072 elements, each FFTComplex is 8 bytes -> ~1MB data

    s = (AVTXContext *)calloc(1, sizeof(AVTXContext));
    s->m = m;
    s->n = m;
    s->inv = 1;
    s->type = 0;

    s->revtab = (int *)malloc(m * sizeof(int));
    in = (FFTComplex *)aligned_alloc(32, m * sizeof(FFTComplex));
    out = (FFTComplex *)aligned_alloc(32, m * sizeof(FFTComplex));

    for (int i = 0; i < m; i++) {
        s->revtab[i] = (i & 1) ? m - 1 - (i >> 1) : (i >> 1);
        if (s->revtab[i] >= m) s->revtab[i] = m - 1;
        in[i].re = i * 2 + 1;
        in[i].im = i * 2;
        out[i].re = 0;
        out[i].im = 0;
    }
}