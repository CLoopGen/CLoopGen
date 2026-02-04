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
    for (i = u->top; i < top; i++) {
        if (!(u->neg)) 
            udp[i] = 0;
    }
}
