#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct AVComplexFloat {
    float re;
    float im;
} AVComplexFloat;

typedef AVComplexFloat FFTComplex;

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
    m = 1 << 20; // 1M elements, ~16MB of FFTComplex data (each 8 bytes)

    s = (AVTXContext*)calloc(1, sizeof(AVTXContext));
    in = (FFTComplex*)calloc(m, sizeof(FFTComplex));
    out = (FFTComplex*)calloc(m, sizeof(FFTComplex));
    s->revtab = (int*)malloc(m * sizeof(int));

    s->n = m;
    s->m = m;
    s->inv = 0;
    s->type = 0;

    for (int i = 0; i < m; i++) {
        in[i].re = (float)i;
        in[i].im = (float)(i * 2);
        s->revtab[i] = (i & ((1 << 20) - 1)) ^ (1 << 20); // dummy bit-reversal-like pattern within bounds
        s->revtab[i] %= m; // ensure it's within [0, m-1]
    }

    // Ensure all pointers are valid and memory is allocated
    s->exptab = NULL;
    s->tmp = NULL;
    s->pfatab = NULL;
}