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

extern BIGNUM *r;
extern unsigned long *rp;
extern unsigned long v;
extern int max;
extern int i;
extern unsigned int rtop;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned long local_v = v;
    for (rtop = r->top, i = 0; i < max; i++) {
        local_v = (unsigned long)0 - ((i - rtop) >> (8 * sizeof(rtop) - 1));
        rp[i] &= local_v;
    }
    v = local_v;
}
