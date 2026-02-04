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
    // Variant 1: Control Dependency Change - Flattened control using computed goto (indirect control flow)
    static void *jump_table[] = {&&label_break, &&label_else};
    int index;
    
    for (;;) {
        index = (a->d[i] >= w) ? 0 : 1;
        goto *jump_table[index];
        
        label_break:
        a->d[i] -= w;
        break;
        
        label_else:
        a->d[i] = (a->d[i] - w) & (18446744073709551615UL);
        i++;
        w = 1;
    }
}
