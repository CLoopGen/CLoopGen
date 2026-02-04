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
    const size_t data_size = 64 * 1024 * 1024; // ~64MB of singlecomplex elements
    const size_t num_elements = data_size / sizeof(singlecomplex);

    // Allocate sh and t arrays
    sh = (singlecomplex*)calloc(num_elements, sizeof(singlecomplex));
    t = (singlecomplex*)calloc(num_elements, sizeof(singlecomplex));

    // Set meaningful dimensions and indices to prevent out-of-bounds access
    t_dim1 = (integer)num_elements > 10000 ? 8192 : (integer)num_elements / 2; // reasonable stride

    // Ensure that the maximum index used: kwtop + i__ - 1 < num_elements
    // Also: i__ + i__ * t_dim1 must be valid index into t
    kwtop = 100;
    infqr = 1;
    i__1 = (integer)(num_elements / t_dim1) - 1; // ensures i__ + i__*t_dim1 <= num_elements-1
    if (i__1 > 50000) i__1 = 50000;

    // Sanitize bounds
    if (i__1 <= infqr) i__1 = infqr + 1;

    // Initialize working memory to zero
    for (size_t idx = 0; idx < num_elements; ++idx) {
        sh[idx].r = 0.0f; sh[idx].i = 0.0f;
        t[idx].r = (real)(idx % 100); t[idx].i = (real)(-(idx % 75));
    }

    // Initialize temporaries
    i__2 = 0;
    i__3 = 0;
}