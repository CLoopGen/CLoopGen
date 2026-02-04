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
    m = 1000000; // Set m so that 15*m ~ 15e6 elements, leading to ~90MB for out and tmp (6B per FFTComplex)

    s = (AVTXContext*)malloc(sizeof(AVTXContext));
    s->m = m;
    s->n = 15 * m;

    s->tmp = (FFTComplex*)calloc(15 * m, sizeof(FFTComplex));
    out_map = (int*)malloc(15 * m * sizeof(int));
    out = (FFTComplex*)malloc(15 * m * sizeof(FFTComplex));

    for (int i = 0; i < 15 * m; i++) {
        out_map[i] = i % (15 * m);
        s->tmp[i].re = (float)(i % 100) / 100.0f;
        s->tmp[i].im = (float)((i + 10) % 100) / 100.0f;
    }
}