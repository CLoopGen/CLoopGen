#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int integer;
typedef double doublereal;

integer n_storage;
doublereal *z__ = NULL;
integer k;

void init_vars() {
    n_storage = 1 << 24;  // Adjust size so loop runs ~0.01s; large enough for measurable work
    while (n_storage > 1000000) n_storage >>= 1;  // Reduce to ~1M iterations for timing
    n_storage = (n_storage / 2) * 2;  // Ensure even

    // The loop accesses indices up to (k << 1) where k starts at *n << 1
    // Max index: (k << 1) = ((*n << 1) << 1) = *n * 4
    // Also accesses (k << 1) - 3, so need at least (*n * 4) + 1 elements
    ptrdiff_t max_index = (n_storage << 1) * 2 + 1;
    z__ = (doublereal*)calloc(max_index + 1, sizeof(doublereal));
    if (!z__) exit(1);
}

integer *n = &n_storage;