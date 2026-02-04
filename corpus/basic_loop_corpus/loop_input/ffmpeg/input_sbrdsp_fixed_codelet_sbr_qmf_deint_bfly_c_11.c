#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int INTFLOAT;

INTFLOAT *v;
INTFLOAT *src0;
INTFLOAT *src1;
int i;

static const size_t DATA_SIZE = 256 * 1024 * sizeof(INTFLOAT); // ~256KB per array

static INTFLOAT *alloc_aligned() {
    void *ptr;
    if (posix_memalign(&ptr, 32, DATA_SIZE)) {
        exit(1);
    }
    return (INTFLOAT *)ptr;
}

void init_vars() {
    v = alloc_aligned();
    src0 = alloc_aligned();
    src1 = alloc_aligned();

    for (size_t idx = 0; idx < DATA_SIZE / sizeof(INTFLOAT); ++idx) {
        src0[idx] = (INTFLOAT)(idx % 1000);
        src1[idx] = (INTFLOAT)((idx + 500) % 1000);
        v[idx] = 0;
    }
}