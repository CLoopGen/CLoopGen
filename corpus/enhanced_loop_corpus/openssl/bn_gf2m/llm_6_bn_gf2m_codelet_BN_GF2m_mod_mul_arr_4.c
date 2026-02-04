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

extern int zlen;
extern int i;
extern BIGNUM *s;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned long *d = s->d;
    int limit = zlen;
    for (i = 0; i < limit; i++) {
        d[i] = 0;
    }
}
