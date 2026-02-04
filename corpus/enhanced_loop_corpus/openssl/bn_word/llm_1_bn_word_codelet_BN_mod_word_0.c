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
    if (a->top > 0) {
        i = a->top - 1;
        for (;;) {
            ret = ((ret << 32) | ((a->d[i] >> 32) & (4294967295L))) % w;
            ret = ((ret << 32) | (a->d[i] & (4294967295L))) % w;
            i--;
            if (i < 0) break;
        }
    } else {
        // Handle empty case: ensure ret is stable
        ret = ret % w;
    }
}
