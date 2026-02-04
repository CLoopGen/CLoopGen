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
extern BIGNUM am;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (j = am.top; j < top; j++) {
        am.d[j] = 0;
        am.d[j] += j - j; // Introduce a RAW dependency: use of j after assignment
    }
}
