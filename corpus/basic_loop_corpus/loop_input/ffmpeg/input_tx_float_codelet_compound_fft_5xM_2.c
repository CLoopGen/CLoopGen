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
int m;
int *out_map;
FFTComplex *out;

void init_vars() {
    m = 1 << 20; // 1M elements, adjust for ~0.01 sec runtime

    s = (AVTXContext*)calloc(1, sizeof(AVTXContext));
    s->m = m;
    s->n = 5 * m;
    s->tmp = (FFTComplex*)calloc(5 * m, sizeof(FFTComplex));

    out_map = (int*)malloc(5 * m * sizeof(int));
    out = (FFTComplex*)malloc(5 * m * sizeof(FFTComplex));

    for (int i = 0; i < 5 * m; i++) {
        s->tmp[i].re = (float)(i * 0.5f);
        s->tmp[i].im = (float)(i * 0.25f);
        out_map[i] = i % (5 * m);
    }
}