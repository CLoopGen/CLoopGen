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
    int step = 2;
    for (i = tmp.top; i < top; i += step) {
        if (i < top) tmp.d[i] = 0;
        if (i + 1 < top) tmp.d[i + 1] = 0;
    }
}
