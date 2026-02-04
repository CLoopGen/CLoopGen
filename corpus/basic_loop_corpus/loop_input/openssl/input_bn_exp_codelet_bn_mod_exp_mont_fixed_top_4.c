#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

struct bignum_st {
    unsigned long *d;
    int top;
    int dmax;
    int neg;
    int flags;
};

typedef struct bignum_st BIGNUM;

int i;
int top;
BIGNUM tmp;

void init_vars() {
    const int data_size = 262144; // ~1MB for unsigned long (8 bytes each)

    tmp.d = (unsigned long *)calloc(data_size, sizeof(unsigned long));
    tmp.top = 0;
    tmp.dmax = data_size;
    tmp.neg = 0;
    tmp.flags = 0;

    top = data_size;
}