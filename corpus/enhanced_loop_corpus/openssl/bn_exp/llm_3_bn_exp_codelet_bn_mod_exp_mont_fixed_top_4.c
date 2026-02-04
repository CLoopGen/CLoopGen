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
    // Variant 2: Strided memory access with step size 4 (SIMD-like pattern)
    int i;
    BIGNUM local_tmp = tmp;
    int start = local_tmp.top;
    int stride = 4;
    // Process every 4th element in four separate passes to simulate vectorization
    for (int offset = 0; offset < stride; offset++) {
        for (i = start + offset; i < top; i += stride) {
            local_tmp.d[i] = 0;
        }
    }
}
