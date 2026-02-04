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
    m = (1 << 24) / (3 * sizeof(FFTComplex)); // Adjust m so that 3*m*sizeof(FFTComplex) is about 16-32MB
    if (m < 1) m = 1;

    out = aligned_alloc(32, 3 * m * sizeof(FFTComplex));
    out_map = malloc(3 * m * sizeof(int));
    s = malloc(sizeof(AVTXContext));
    s->tmp = aligned_alloc(32, 3 * m * sizeof(FFTComplex));

    for (int i = 0; i < 3 * m; i++) {
        out[i].re = 0.0;
        out[i].im = 0.0;
        s->tmp[i].re = (double)i;
        s->tmp[i].im = (double)(i * 2);
        out_map[i] = i % (3 * m);
    }
}