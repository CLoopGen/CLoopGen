#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef float real;

typedef struct {
    real r;
    real i;
} singlecomplex;

typedef int integer;

singlecomplex *sh;
singlecomplex *t;
integer t_dim1;
integer i__1;
integer i__2;
integer i__3;
integer i__;
integer infqr;
integer kwtop;

void init_vars() {
    // Set problem size to ensure loop runs ~0.01 seconds
    // Estimate: each iteration does two float assignments -> light operation
    // Aim for several million iterations to reach 0.01s on modern CPU

    const int total_elements = 8000000;  // ~8M elements, adjust as needed

    // Allocate sh and t arrays with sufficient size
    sh = (singlecomplex*)calloc(total_elements + 1, sizeof(singlecomplex));
    t = (singlecomplex*)calloc(total_elements + 1, sizeof(singlecomplex));

    // Avoid null pointers or invalid memory access
    if (!sh || !t) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    // Set matrix dimension and loop bounds
    t_dim1 = 4000;  // assumed leading dimension of t

    // Set meaningful values for the loop:
    infqr = 1000;
    i__1 = 3000;  // so loop runs from infqr+1 to i__1 => 2000 iterations

    kwtop = 500;

    // Ensure all array accesses are in bounds:
    // i__ ranges from infqr+1 (1001) to i__1 (3000)
    // i__2 = kwtop + i__ - 1 => ranges from 500+1001-1=1500 to 500+3000-1=3499
    // i__3 = i__ + i__*t_dim1 = i__(t_dim1+1) => from 1001*4001=4,005,001 to 3000*4001=12,003,000
    //
    // So we need t[i__3] to be valid up to ~12e6 -> our allocation covers this

    // However, note: i__3 index grows quickly. Our t array must be large enough.
    // We allocated 8M, but max i__3 is ~12M -> so increase allocation

    free(sh);
    free(t);

    const int new_size = 13000000;  // >12.003M
    sh = (singlecomplex*)calloc(new_size, sizeof(singlecomplex));
    t = (singlecomplex*)calloc(new_size, sizeof(singlecomplex));

    if (!sh || !t) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    // Reinitialize derived parameters (already set, just ensuring)
    t_dim1 = 4000;
    infqr = 1000;
    i__1 = 3000;
    kwtop = 500;

    // Initialize some sample data to avoid undefined behavior when reading t
    for (int idx = 0; idx < new_size; ++idx) {
        t[idx].r = (real)(idx % 100) / 100.0f;
        t[idx].i = (real)((idx + 10) % 100) / 100.0f;
    }
}