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
    m = 1 << 20;  // ~1 million elements, scales 3*m to ~3M accesses

    s = (AVTXContext *)calloc(1, sizeof(AVTXContext));
    s->m = m;
    s->n = 3 * m;
    s->tmp = (FFTComplex *)calloc(3 * m, sizeof(FFTComplex));

    out_map = (int *)malloc(3 * m * sizeof(int));
    out = (FFTComplex *)malloc(3 * m * sizeof(FFTComplex));

    for (int i = 0; i < 3 * m; i++) {
        s->tmp[i].re = (float)(i % 100) + 0.5f;
        s->tmp[i].im = (float)((i + 10) % 100) + 0.25f;
        out_map[i] = i;  // valid index within [0, 3*m)
    }
}