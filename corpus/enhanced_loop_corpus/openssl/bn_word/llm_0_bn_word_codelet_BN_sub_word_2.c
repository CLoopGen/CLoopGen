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
    for (; i < a->top; ) {
        for (int inner = 0; inner < 1; inner++) {
            if (a->d[i] >= w) {
                a->d[i] -= w;
                goto exit_loop;
            } else {
                a->d[i] = (a->d[i] - w) & (18446744073709551615UL);
                i++;
                w = 1;
            }
        }
    }
exit_loop:;
}
