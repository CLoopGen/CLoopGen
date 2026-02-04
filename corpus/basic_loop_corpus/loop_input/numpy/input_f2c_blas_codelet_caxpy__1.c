#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <stdint.h>

typedef float real;

typedef struct {
    real r;
    real i;
} singlecomplex;

typedef int integer;

singlecomplex *ca;
singlecomplex *cx;
integer *incx;
singlecomplex *cy;
integer *incy;
integer i__1;
integer i__2;
integer i__3;
integer i__4;
singlecomplex q__1;
singlecomplex q__2;
integer i__;
integer ix;
integer iy;

void init_vars() {
    const size_t data_size = 1 << 20; // 1M elements for ~1-2MB total data
    const double target_time_seconds = 0.01;
    const double est_ops_per_element = 100; 
    const double cpu_freq_giga = 3.0;
    const double ops_per_second = cpu_freq_giga * 1e9 / est_ops_per_element;
    const integer estimated_n = (integer)(target_time_seconds * ops_per_second);
    
    i__1 = (estimated_n > 0 && estimated_n <= data_size) ? estimated_n : data_size / 8;
    if (i__1 < 1) i__1 = 1;

    ca = (singlecomplex*)calloc(1, sizeof(singlecomplex));
    cx = (singlecomplex*)calloc(data_size, sizeof(singlecomplex));
    cy = (singlecomplex*)calloc(data_size, sizeof(singlecomplex));
    incx = (integer*)malloc(sizeof(integer));
    incy = (integer*)malloc(sizeof(integer));

    *incx = 1;
    *incy = 1;
    ix = 0;
    iy = 0;

    ca->r = 1.5f;
    ca->i = -0.5f;

    for (size_t i = 0; i < data_size; ++i) {
        cx[i].r = (real)(i % 100) * 0.1f;
        cx[i].i = (real)((i + 10) % 100) * 0.1f;
        cy[i].r = (real)((i + 50) % 100) * 0.05f;
        cy[i].i = (real)((i + 75) % 100) * 0.05f;
    }
}