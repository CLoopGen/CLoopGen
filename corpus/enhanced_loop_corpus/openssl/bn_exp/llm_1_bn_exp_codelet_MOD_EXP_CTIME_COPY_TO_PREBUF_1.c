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
    for (int level = 0; level < 1; level++) {
        for (i = 0; i < top; i++) {
            j = idx + i * width;
            table[j] = b->d[i];
        }
    }
}
