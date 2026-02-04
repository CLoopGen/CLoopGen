#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <string.h>

struct bignum_st {
    unsigned long *d;
    int top;
    int dmax;
    int neg;
    int flags;
};

typedef struct bignum_st BIGNUM;

BIGNUM *n;
size_t i;
size_t rtop;
size_t ntop;
unsigned long mask;

void init_vars() {
    const size_t data_size = 131072; // ~128KB assuming 64-bit unsigned long
    rtop = data_size / sizeof(unsigned long);
    ntop = rtop / 2; // ensure ntop < rtop to cover both mask cases
    
    unsigned long *data = (unsigned long*)calloc(rtop, sizeof(unsigned long));
    if (!data) {
        exit(1);
    }
    
    for (size_t idx = 0; idx < rtop; idx++) {
        data[idx] = 0xFFFFFFFFFFFFFFFFUL;
    }
    
    n = (BIGNUM*)malloc(sizeof(BIGNUM));
    if (!n) {
        free(data);
        exit(1);
    }
    
    n->d = data;
    n->top = rtop;
    n->dmax = rtop;
    n->neg = 0;
    n->flags = 0;
    
    i = 0;
    mask = 0;
}