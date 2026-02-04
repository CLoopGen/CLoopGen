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



void loop() {
    for (i = am.top; i < top && i < am.dmax; i++) {
        am.d[i] = (unsigned long)(i * i + 3 * i + 2);
    }
}
