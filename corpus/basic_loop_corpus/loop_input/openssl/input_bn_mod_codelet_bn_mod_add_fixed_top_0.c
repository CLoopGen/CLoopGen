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

static unsigned long *alloc_aligned_ulong_array(size_t n) {
    void *ptr;
    if (posix_memalign(&ptr, 32, n * sizeof(unsigned long)) != 0) {
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
unsigned long carry;
unsigned long temp;
unsigned long mask;
unsigned long *tp;
unsigned long *ap;
unsigned long *bp;

void init_vars() {
    const size_t data_size = 131072; // ~128KB of data

    unsigned long *data_a = alloc_aligned_ulong_array(data_size);
    unsigned long *data_b = alloc_aligned_ulong_array(data_size);
    unsigned long *data_t = alloc_aligned_ulong_array(data_size);

    for (size_t idx = 0; idx < data_size; idx++) {
        data_a[idx] = (unsigned long)(idx * 17 + 1);
        data_b[idx] = (unsigned long)(idx * 31 + 7);
        data_t[idx] = 0;
    }

    a = (BIGNUM*)malloc(sizeof(BIGNUM));
    b = (BIGNUM*)malloc(sizeof(BIGNUM));

    a->d = data_a;
    a->top = (int)(data_size * 0.8);
    a->dmax = (int)data_size;
    a->neg = 0;
    a->flags = 0;

    b->d = data_b;
    b->top = (int)(data_size * 0.8);
    b->dmax = (int)data_size;
    b->neg = 0;
    b->flags = 0;

    tp = data_t;
    ap = a->d;
    bp = b->d;

    mtop = data_size;
}