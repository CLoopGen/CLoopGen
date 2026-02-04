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
    m = 1000000; // Set m so that 15*m ~ 15e6 elements, leading to ~100MB of data

    s = (AVTXContext*)calloc(1, sizeof(AVTXContext));
    s->m = m;
    s->tmp = (FFTComplex*)calloc(15 * m, sizeof(FFTComplex));

    out_map = (int*)malloc(15 * m * sizeof(int));
    for (int i = 0; i < 15 * m; i++) {
        out_map[i] = i % (15 * m); // valid index within tmp bounds
    }

    out = (FFTComplex*)calloc(15 * m, sizeof(FFTComplex));
}