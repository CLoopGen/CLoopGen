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

extern  BIGNUM *a;
extern unsigned long w;
extern unsigned long ret;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned long local_ret = 0;
    int j;
    for (j = a->top - 1; j >= 0; j--) {
        unsigned long word = a->d[j];
        unsigned long parts[2] = {
            word & 4294967295UL,
            (word >> 32) & 4294967295UL
        };
        for (int k = 1; k >= 0; k--) {
            local_ret = ((local_ret << 32) | parts[k]) % w;
        }
    }
    ret = local_ret;
}
