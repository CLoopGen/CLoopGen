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
    m = 1 << 24; // ~16.7 million elements, ensures loop runs ~0.01s on modern CPU

    s = (AVTXContext*)calloc(1, sizeof(AVTXContext));
    if (!s) exit(1);

    s->m = m;
    s->n = 5 * m;

    s->tmp = (FFTComplex*)calloc(5 * m, sizeof(FFTComplex));
    if (!s->tmp) exit(1);

    out_map = (int*)malloc(5 * m * sizeof(int));
    if (!out_map) exit(1);

    for (int i = 0; i < 5 * m; i++) {
        out_map[i] = i; // valid index within [0, 5*m)
    }

    out = (FFTComplex*)calloc(5 * m, sizeof(FFTComplex));
    if (!out) exit(1);
}