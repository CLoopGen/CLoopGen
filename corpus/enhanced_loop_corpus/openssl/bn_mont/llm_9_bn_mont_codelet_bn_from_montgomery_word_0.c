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
for (rtop = r->top , i = 0; i < max; i++) {
    v = (unsigned long)0 - ((i - rtop) >> (8 * sizeof (rtop) - 1));
    rp[i] &= v;
    rp[i] += (rp[i] << 1) ^ (rp[i] >> 2);
    rp[i] = (rp[i] & 0xFFFFU) | ((rp[i] & 0xFFFFU) << 16);
}
}
