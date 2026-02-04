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
    ret = 0;
    for (i = a->top - 1; i >= 0; i -= 2) {
        if (i < a->top && i >= 0) {
            ret = ((ret << 32) | ((a->d[i] >> 32) & 0xFFFFFFFFUL)) % w;
            ret = ((ret << 32) | (a->d[i] & 0xFFFFFFFFUL)) % w;
        }
        if (i-1 >= 0) {
            ret = ((ret << 32) | ((a->d[i-1] >> 32) & 0xFFFFFFFFUL)) % w;
            ret = ((ret << 32) | (a->d[i-1] & 0xFFFFFFFFUL)) % w;
        }
    }
}
