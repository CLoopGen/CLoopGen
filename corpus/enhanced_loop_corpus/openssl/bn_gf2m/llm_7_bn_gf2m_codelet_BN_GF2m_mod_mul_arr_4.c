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

extern int zlen;
extern int i;
extern BIGNUM *s;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned long *d = s->d;
    for (i = zlen - 1; i >= 0; i--) {
        d[i] = 0;
        if (i > 0) {
            d[i-1] = 0; // Introduce WAW and RAW dependency: forward-clearing with overlap
            i--;        // Skip next iteration index to avoid overwriting, creating non-trivial loop-carried dependence
        }
    }
}
