#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

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

static unsigned long *rr_d;
static unsigned long *n_d;

BIGNUM static_rr;
BIGNUM static_n;

BN_MONT_CTX global_mont;
BN_MONT_CTX *mont = &global_mont;

int i;
int ret;

void init_vars() {
    const size_t data_size = 1024 * 256 / sizeof(unsigned long); 

    rr_d = (unsigned long *)calloc(data_size, sizeof(unsigned long));
    n_d = (unsigned long *)calloc(data_size, sizeof(unsigned long));

    static_rr.d = rr_d;
    static_rr.top = 0;
    static_rr.dmax = data_size;
    static_rr.neg = 0;
    static_rr.flags = 0;

    static_n.d = n_d;
    static_n.top = data_size;
    static_n.dmax = data_size;
    static_n.neg = 0;
    static_n.flags = 0;

    global_mont.RR = static_rr;
    global_mont.N = static_n;
    global_mont.Ni = static_n;
    global_mont.n0[0] = 0;
    global_mont.n0[1] = 0;
    global_mont.ri = 0;
    global_mont.flags = 0;

    i = 0;
    ret = 0;
}