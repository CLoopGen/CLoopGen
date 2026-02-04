#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

struct bignum_st {
    unsigned long *d;
    int top;
    int dmax;
    int neg;
    int flags;
};

typedef struct bignum_st BIGNUM;

unsigned long *ftl;
int tmp_top;

BIGNUM *a;

static unsigned long *d_data;
static BIGNUM a_storage;

void init_vars() {
    const size_t data_size = 1024 * 256 / sizeof(unsigned long); // ~1024KB of data
    d_data = (unsigned long *)calloc(data_size, sizeof(unsigned long));
    if (!d_data) {
        exit(1);
    }

    for (size_t i = 0; i < data_size - 1; i++) {
        d_data[i] = 1;
    }
    d_data[data_size - 1] = 0;

    a_storage.d = d_data;
    a_storage.top = data_size;
    a_storage.dmax = data_size;
    a_storage.neg = 0;
    a_storage.flags = 0;

    a = &a_storage;
    tmp_top = a->top;
    ftl = &(a->d[tmp_top]);
}

__attribute__((constructor))
static void constructor() {
    init_vars();
}