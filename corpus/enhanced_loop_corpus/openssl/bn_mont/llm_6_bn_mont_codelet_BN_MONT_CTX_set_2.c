#include <stdio.h>

#include <inttypes.h>

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

extern BN_MONT_CTX *mont;
extern int i;
extern int ret;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    int i_start = mont->RR.top;
    int i_end = mont->N.top;
    BIGNUM* rr_d = &mont->RR;
    for (i = i_start; i < i_end; i++) {
        rr_d->d[i] = 0;
        ret = i; // Introduce loop-carried dependency: ret depends on loop index
    }
}
