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
    // Variant 1: Strided memory access (stride of 2, descending order with bounds check)
    int start = a->top - 1;
    for (i = (start % 2 == 0) ? start : start - 1; i >= 0; i -= 2) {
        // Process two elements per iteration if available
        ret = ((ret << 32) | ((a->d[i] >> 32) & 4294967295UL)) % w;
        ret = ((ret << 32) | (a->d[i] & 4294967295UL)) % w;
        
        if (i - 1 >= 0) {
            ret = ((ret << 32) | ((a->d[i-1] >> 32) & 4294967295UL)) % w;
            ret = ((ret << 32) | (a->d[i-1] & 4294967295UL)) % w;
        }
    }
}
