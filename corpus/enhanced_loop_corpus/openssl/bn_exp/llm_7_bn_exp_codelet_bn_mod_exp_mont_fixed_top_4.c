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
    int offset = tmp.top;
    int count = top - tmp.top;
    for (int k = 0; k < count; k++) {
        tmp.d[offset + k] = 0;
        tmp.d[offset + k + 1 - 1] = tmp.d[offset + k]; // Introduces WAW (write-after-write) and loop-carried flow dependency
    }
}
