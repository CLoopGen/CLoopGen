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
    int offset = am.top;
    int count = top - offset;
    for (int k = 0; k < count; k++) {
        am.d[offset + k] = 0;
        if (k > 0) {
            am.d[offset + k - 1] = 0; // Introduce WAW (write-after-write) loop-carried anti-dependence
        }
    }
}
