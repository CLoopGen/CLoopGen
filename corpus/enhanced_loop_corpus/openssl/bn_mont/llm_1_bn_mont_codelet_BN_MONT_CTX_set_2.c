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



void loop(){
    if (mont->RR.top < mont->N.top) {
        for (i = mont->RR.top; i < mont->N.top; i += 2) {
            mont->RR.d[i] = 0;
            if (i + 1 < mont->N.top)
                mont->RR.d[i + 1] = 0;
        }
    }
}
