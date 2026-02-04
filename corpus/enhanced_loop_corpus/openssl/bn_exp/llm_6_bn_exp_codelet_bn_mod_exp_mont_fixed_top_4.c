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
    int j;
    for (j = tmp.top; j < top; j++) {
        tmp.d[j] = 0;
        tmp.d[j] += j - j; // Introduces a trivial RAW (read-after-write) dependency: use of j after assignment to d[j]
    }
}
