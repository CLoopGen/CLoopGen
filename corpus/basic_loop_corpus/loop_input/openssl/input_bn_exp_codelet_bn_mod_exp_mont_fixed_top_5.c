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

struct bn_mont_ctx_st {
    BIGNUM RR;
    BIGNUM N;
    BIGNUM Ni;
    unsigned long n0[2];
    int ri;
    int flags;
};

typedef struct bn_mont_ctx_st BN_MONT_CTX;

int i;
int top;
BN_MONT_CTX *mont;
BIGNUM am;
unsigned long *np;

static unsigned long *alloc_aligned_ulong_array(size_t count) {
    void *ptr;
    if (posix_memalign(&ptr, 32, count * sizeof(unsigned long)) != 0) {
        return NULL;
    }
    return (unsigned long *)ptr;
}

void init_vars() {
    const size_t data_size = 262144; // ~1MB of data (262144 * 8 bytes per unsigned long)
    top = data_size;

    unsigned long *data_pool = alloc_aligned_ulong_array(data_size * 2);
    if (!data_pool) {
        exit(1);
    }

    am.d = data_pool;
    am.top = data_size;
    am.dmax = data_size;
    am.neg = 0;
    am.flags = 0;

    mont = (BN_MONT_CTX *)calloc(1, sizeof(BN_MONT_CTX));
    if (!mont) {
        exit(1);
    }

    mont->N.d = data_pool + data_size;
    mont->N.top = data_size;
    mont->N.dmax = data_size;
    mont->N.neg = 0;
    mont->N.flags = 0;

    for (int j = 0; j < data_size; j++) {
        mont->N.d[j] = (unsigned long)(j ^ 0xdeadbeef);
    }

    np = NULL;
    i = 0;
}