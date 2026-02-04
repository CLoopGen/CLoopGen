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

extern BIGNUM *n;
extern size_t i;
extern size_t rtop;
extern size_t ntop;
extern unsigned long mask;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < rtop; i++) {
        if (i >= ntop) {
            n->d[i] &= mask;
        }
    }
}
