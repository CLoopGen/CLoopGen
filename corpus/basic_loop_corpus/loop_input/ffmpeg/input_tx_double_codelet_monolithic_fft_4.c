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
FFTComplex *in;
FFTComplex *out;
int m;

void init_vars() {
    m = 1 << 20; // 1 million elements, ~16MB of data (each complex double is 16 bytes)

    s = (AVTXContext *)calloc(1, sizeof(AVTXContext));
    in = (FFTComplex *)calloc(m, sizeof(FFTComplex));
    out = (FFTComplex *)calloc(m, sizeof(FFTComplex));
    s->revtab = (int *)calloc(m, sizeof(int));

    s->n = m;
    s->m = m;

    for (int i = 0; i < m; i++) {
        in[i].re = (double)i;
        in[i].im = (double)(i * 2);
        s->revtab[i] = (i & ((1 << 20) - 1)) ^ (1 << 19); // valid permutation within [0, m)
        if (s->revtab[i] >= m) {
            s->revtab[i] %= m;
        }
    }
}