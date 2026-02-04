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

extern int i;
extern int top;
extern BIGNUM tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with unrolled stride of 2
    int i;
    int limit = top - (top % 2);
    BIGNUM local_tmp = tmp; // Avoid repeated struct access
    for (i = local_tmp.top; i < limit; i += 2) {
        local_tmp.d[i] = 0;
        local_tmp.d[i + 1] = 0;
    }
    // Handle remaining element if top is odd
    for (; i < top; i++) {
        local_tmp.d[i] = 0;
    }
}
