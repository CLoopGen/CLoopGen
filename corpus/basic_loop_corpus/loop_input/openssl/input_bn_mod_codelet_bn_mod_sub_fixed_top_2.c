#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

struct bignum_st {
    unsigned long *d;
    int top;
    int dmax;
    int neg;
    int flags;
};

typedef struct bignum_st BIGNUM;

static unsigned long *alloc_aligned_size(size_t size) {
    void *ptr;
    if (posix_memalign(&ptr, 32, size) != 0) {
        exit(1);
    }
    return (unsigned long *)ptr;
}

BIGNUM *a;
BIGNUM *b;
size_t i;
size_t ai;
size_t bi;
size_t mtop;
unsigned long borrow;
unsigned long ta;
unsigned long tb;
unsigned long mask;
unsigned long *rp;
unsigned long *ap;
unsigned long *bp;

void init_vars() {
    const size_t data_size = 131072; // 128KB of data
    const size_t num_longs = data_size / sizeof(unsigned long);

    a = (BIGNUM *)calloc(1, sizeof(BIGNUM));
    b = (BIGNUM *)calloc(1, sizeof(BIGNUM));

    a->d = alloc_aligned_size(data_size);
    b->d = alloc_aligned_size(data_size);
    rp = alloc_aligned_size(data_size);

    ap = a->d;
    bp = b->d;

    a->top = (int)(num_longs * 3 / 4);
    b->top = (int)(num_longs * 2 / 3);
    a->dmax = (int)num_longs;
    b->dmax = (int)num_longs;

    mtop = num_longs;

    for (size_t idx = 0; idx < num_longs; idx++) {
        a->d[idx] = (unsigned long)(idx * 17 + 1);
        b->d[idx] = (unsigned long)(idx * 11 + 5);
    }

    i = 0;
    ai = 0;
    bi = 0;
    borrow = 0;
}