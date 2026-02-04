#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct AVComplexDouble {
    double re;
    double im;
} AVComplexDouble;

typedef AVComplexDouble FFTComplex;

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
    m = 1000000; // This makes 15 * m = 15e6 iterations

    s = (AVTXContext*)calloc(1, sizeof(AVTXContext));
    s->m = m;
    s->n = 15 * m;

    s->tmp = (FFTComplex*)calloc(15 * m, sizeof(FFTComplex));
    out_map = (int*)malloc(15 * m * sizeof(int));
    out = (FFTComplex*)malloc(15 * m * sizeof(FFTComplex));

    for (int i = 0; i < 15 * m; i++) {
        s->tmp[i].re = (double)i;
        s->tmp[i].im = (double)(i * 2);
        out_map[i] = i; // identity mapping to stay in bounds
    }
}

__attribute__((constructor))
static void constructor_call() {
    init_vars();
}