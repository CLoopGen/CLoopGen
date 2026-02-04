#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

struct bignum_st {
    unsigned long *d;
    int top;
    int dmax;
    int neg;
    int flags;
};

typedef struct bignum_st BIGNUM;

static unsigned long *d_array;
static BIGNUM a_storage;
BIGNUM *a = &a_storage;
int i;
int k;

void init_vars() {
    const size_t data_size = 1024 * 128; // ~128KB of data
    const int num_elements = data_size / sizeof(unsigned long);
    
    d_array = (unsigned long *)calloc(num_elements, sizeof(unsigned long));
    
    a->d = d_array;
    a->top = num_elements / 2;
    a->dmax = num_elements;
    a->neg = 0;
    a->flags = 0;
    
    i = num_elements - 1;
    k = 0;
}