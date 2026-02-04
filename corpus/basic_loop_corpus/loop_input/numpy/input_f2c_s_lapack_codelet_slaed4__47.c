#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

typedef int integer;
typedef float real;

integer *n;
real *z__;
real *delta;
integer i__1;
integer j;
real phi;
real dphi;
real temp;
real erretm;

static real *z__buf;
static real *delta_buf;
static const size_t data_size = 64 * 1024 * 1024 / sizeof(real); // ~256MB total

void init_vars() {
    z__buf = (real *)calloc(data_size, sizeof(real));
    delta_buf = (real *)calloc(data_size, sizeof(real));
    if (!z__buf || !delta_buf) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t i = 0; i < data_size; ++i) {
        z__buf[i] = (real)(rand() % 100) / 10.0f;
        delta_buf[i] = (real)(rand() % 100) / 10.0f + 1.0f;
    }

    n = (integer *)malloc(sizeof(integer));
    *n = (integer)(data_size - 1);

    z__ = z__buf;
    delta = delta_buf;

    i__1 = 1;
    j = 0;
    phi = 0.0f;
    dphi = 0.0f;
    temp = 0.0f;
    erretm = 0.0f;
}