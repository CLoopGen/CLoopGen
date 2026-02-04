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
extern BIGNUM am;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with step size of 4 (SIMD-like pattern)
    int i;
    int stride = 4;
    // Process every 4th element first, in four separate phases
    for (int phase = 0; phase < stride; phase++) {
        for (i = am.top + phase; i < top; i += stride) {
            am.d[i] = 0;
        }
    }
}
