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

extern int i;
extern int top;
extern BN_MONT_CTX *mont;
extern BIGNUM am;
extern unsigned long *np;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    np = am.d + top;
    unsigned long prev = 0;
    for (i = 0; i < top; i++) {
        np[i] = mont->N.d[i] ^ prev;
        prev = np[i];
    }
}
