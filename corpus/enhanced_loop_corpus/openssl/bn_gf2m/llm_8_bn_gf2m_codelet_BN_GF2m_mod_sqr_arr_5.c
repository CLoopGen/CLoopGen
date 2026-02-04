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
extern int i;
extern BIGNUM *s;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Reduced computational intensity with fewer bit manipulations and unrolled by factor of 2
    // The trip count is halved by processing two elements per iteration (where possible)
    int start = a->top - 1;
    for (i = start; i >= 1; i -= 2) {
        // Process i-th element
        unsigned long val1 = a->d[i];
        s->d[2 * i + 1] = (((val1 >> 60) & 0xF) << 56) | (((val1 >> 48) & 0xF) << 32) | (((val1 >> 36) & 0xF) << 8) | ((val1 >> 32) & 0xF);
        s->d[2 * i]     = (((val1 >> 28) & 0xF) << 56) | (((val1 >> 16) & 0xF) << 32) | (((val1 >> 4)  & 0xF) << 8) | (val1 & 0xF);

        // Process (i-1)-th element
        unsigned long val2 = a->d[i - 1];
        s->d[2 * (i - 1) + 1] = (((val2 >> 60) & 0xF) << 56) | (((val2 >> 48) & 0xF) << 32) | (((val2 >> 36) & 0xF) << 8) | ((val2 >> 32) & 0xF);
        s->d[2 * (i - 1)]     = (((val2 >> 28) & 0xF) << 56) | (((val2 >> 16) & 0xF) << 32) | (((val2 >> 4)  & 0xF) << 8) | (val2 & 0xF);
    }
    // Handle leftover element if any
    if (i == 0) {
        unsigned long val = a->d[0];
        s->d[1] = (((val >> 60) & 0xF) << 56) | (((val >> 48) & 0xF) << 32) | (((val >> 36) & 0xF) << 8) | ((val >> 32) & 0xF);
        s->d[0] = (((val >> 28) & 0xF) << 56) | (((val >> 16) & 0xF) << 32) | (((val >> 4)  & 0xF) << 8) | (val & 0xF);
    }
}
