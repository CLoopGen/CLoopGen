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
extern unsigned long w;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned long temp;
    for (;;) {
        temp = a->d[i];
        if (temp >= w) {
            a->d[i] = temp - w;
            break;
        } else {
            a->d[i] = (temp - w) & (18446744073709551615UL);
            i++;
            w = 1;
        }
    }
}
