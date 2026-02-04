#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct bignum_st {
    unsigned long *d;
    int top;
    int dmax;
    int neg;
    int flags;
};

typedef struct bignum_st BIGNUM;

unsigned long condition = 0x55555555UL;
BIGNUM *a;
BIGNUM *b;
int nwords;
unsigned long t;
int i;

void init_vars() {
    nwords = 16384; 

    a = (BIGNUM *)malloc(sizeof(BIGNUM));
    b = (BIGNUM *)malloc(sizeof(BIGNUM));
    
    a->d = (unsigned long *)aligned_alloc(64, nwords * sizeof(unsigned long));
    b->d = (unsigned long *)aligned_alloc(64, nwords * sizeof(unsigned long));
    
    a->top = nwords;
    a->dmax = nwords;
    a->neg = 0;
    a->flags = 0;
    
    b->top = nwords;
    b->dmax = nwords;
    b->neg = 0;
    b->flags = 0;
    
    for (int j = 0; j < nwords; j++) {
        a->d[j] = (unsigned long)(j * 31 + 1);
        b->d[j] = (unsigned long)(j * 17 + 2);
    }
    
    condition = 0xAAAAAAAAUL;
    t = 0;
    i = 0;
}