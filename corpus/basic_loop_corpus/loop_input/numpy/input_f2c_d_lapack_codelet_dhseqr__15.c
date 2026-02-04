#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int integer;
typedef double doublereal;

integer *ihi;
doublereal *h__;
doublereal *wr;
doublereal *wi;
integer h_dim1;
integer i__1;
integer i__;

void init_vars() {
    const size_t N = 20000; // Adjusted to ensure loop runs ~0.01s

    h_dim1 = N;
    i__1 = N;
    *ihi = N - 1000; // ensures i__ starts within valid range and runs for 1000 iterations

    h__ = (doublereal *)calloc((N + 1) * (N + 1), sizeof(doublereal));
    wr = (doublereal *)calloc(N + 1, sizeof(doublereal));
    wi = (doublereal *)calloc(N + 1, sizeof(doublereal));

    // Ensure memory initialization is not optimized away
    if (!h__ || !wr || !wi) {
        exit(1);
    }
}

// Allocate and initialize external variables
static integer _ihi_storage;
static char _init_done = 0;

__attribute__((constructor))
void _init_globals(void) {
    if (!_init_done) {
        ihi = &_ihi_storage;
        init_vars();
        _init_done = 1;
    }
}