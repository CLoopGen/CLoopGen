#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef float FFTSample;

typedef struct FFTComplex {
    FFTSample re;
    FFTSample im;
} FFTComplex;

FFTComplex *xa;
FFTComplex *xb;
int window;
FFTComplex *xc;
int i;

static FFTComplex *xa_data;
static FFTComplex *xb_data;
static FFTComplex *xc_data;

void init_vars() {
    size_t data_size = 1 << 23; // ~67M floats, ~268MB for three arrays of complex
    xa_data = calloc(data_size, sizeof(FFTComplex));
    xb_data = calloc(data_size, sizeof(FFTComplex));
    xc_data = calloc(data_size, sizeof(FFTComplex));

    if (!xa_data || !xb_data || !xc_data) {
        exit(1);
    }

    for (size_t idx = 0; idx < data_size; idx++) {
        xa_data[idx].re = 1.0f + idx * 0.0001f;
        xa_data[idx].im = 0.5f + idx * 0.00005f;
        xb_data[idx].re = 2.0f - idx * 0.00001f;
        xb_data[idx].im = 1.5f + idx * 0.00002f;
        xc_data[idx].re = 0.0f;
        xc_data[idx].im = 0.0f;
    }

    xa = xa_data;
    xb = xb_data;
    xc = xc_data;
    window = (int)data_size;
    i = 0;
}