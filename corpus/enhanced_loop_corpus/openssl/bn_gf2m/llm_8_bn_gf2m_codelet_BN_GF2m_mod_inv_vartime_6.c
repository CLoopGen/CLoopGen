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

extern BIGNUM *u;
extern int i;
extern int top;
extern unsigned long *udp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int start = u->top;
    int end = top;
    for (i = start; i < end; i += 2) {
        if (i < end) udp[i] = 0;
        if (i + 1 < end) udp[i + 1] = 0;
    }
}
