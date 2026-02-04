#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

ptrdiff_t ilinesize;
ptrdiff_t tlinesize;
ptrdiff_t flinesize;
ptrdiff_t slinesize;
ptrdiff_t olinesize;
int w;
int h;
uint16_t *in;
uint16_t *threshold;
uint16_t *min;
uint16_t *max;
uint16_t *out;
int x;
int y;

static uint16_t *alloc_aligned_size(ptrdiff_t size) {
    void *ptr;
    if (posix_memalign(&ptr, 32, size) != 0) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }
    return (uint16_t *)ptr;
}

void init_vars() {
    w = 1024;
    h = 512;

    ptrdiff_t elem_size = sizeof(uint16_t);

    ilinesize = w * elem_size;
    tlinesize = w * elem_size;
    flinesize = w * elem_size;
    slinesize = w * elem_size;
    olinesize = w * elem_size;

    size_t total_size = (size_t)h * w * elem_size;

    in = alloc_aligned_size(total_size);
    threshold = alloc_aligned_size(total_size);
    min = alloc_aligned_size(total_size);
    max = alloc_aligned_size(total_size);
    out = alloc_aligned_size(total_size);

    for (size_t i = 0; i < h * w; i++) {
        in[i] = rand() % 65536;
        threshold[i] = rand() % 65536;
        min[i] = rand() % 65536;
        max[i] = rand() % 65536;
    }

    x = 0;
    y = 0;
}