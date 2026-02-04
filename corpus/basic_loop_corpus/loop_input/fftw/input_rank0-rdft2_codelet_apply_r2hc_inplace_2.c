#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef double R;
typedef ptrdiff_t INT;
typedef R E;

R *ci;
INT i;
INT vl;
INT ovs;

static R *ci_storage;
static INT storage_size;

void init_vars() {
    storage_size = 64 * 1024 * 1024 / sizeof(R);  // ~64 MB of data
    ci_storage = (R*)calloc(storage_size, sizeof(R));
    if (!ci_storage) {
        exit(1);
    }

    ci = ci_storage;
    ovs = 1;
    vl = storage_size - 4;  // ensures ci[i] accesses stay within bounds when stepping by 4*ovs
    i = 0;
}