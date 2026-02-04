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
    m = 1 << 24;  // ~67M iterations (5*m), aiming for ~0.01 sec on modern CPU with proper data size

    s = (AVTXContext *)calloc(1, sizeof(AVTXContext));
    if (!s) exit(1);

    s->m = m;
    s->n = 5 * m;

    s->tmp = (FFTComplex *)calloc(5 * m, sizeof(FFTComplex));
    if (!s->tmp) exit(1);

    out_map = (int *)malloc(5 * m * sizeof(int));
    if (!out_map) exit(1);

    for (int i = 0; i < 5 * m; i++) {
        out_map[i] = i % (5 * m);
    }

    out = (FFTComplex *)malloc(5 * m * sizeof(FFTComplex));
    if (!out) exit(1);
}