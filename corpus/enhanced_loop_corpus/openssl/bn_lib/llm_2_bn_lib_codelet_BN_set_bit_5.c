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
extern int i;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Strided memory access (stride of 2) with bounds check
    int start = a->top;
    int end = i + 1;
    for (k = start; k < end; k += 2)
        a->d[k] = 0;
    // Handle odd index if range ends on odd index
    if ((end - start) > 0 && (start % 2) != (end % 2) && (end - 1) % 2 == 1)
        a->d[end - 1] = 0;
}
