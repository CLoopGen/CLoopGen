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

extern BIGNUM *a;
extern unsigned long w;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (stride of 2)
    int stride = 2;
    for (;;) {
        int idx = i * stride; // Apply striding to index
        if (idx >= a->dmax) break; // Safety bound check
        if (a->d[idx] >= w) {
            a->d[idx] -= w;
            break;
        } else {
            a->d[idx] = (a->d[idx] - w) & (18446744073709551615UL);
            i++;
            w = 1;
        }
    }
}
