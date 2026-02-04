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

extern  BIGNUM *b;
extern int top;
extern int idx;
extern int i;
extern int j;
extern int width;
extern unsigned long *table;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0, j = idx; i < top; i++, j += width) {
        if (i % 2 == 0) {
            table[j] = b->d[i];
        } else {
            table[j] = 0;
        }
    }
}
