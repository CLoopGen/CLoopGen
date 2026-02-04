#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

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
BIGNUM am;

static unsigned long *d_array;

void init_vars() {
    // Allocate data size to make loop run ~0.01 seconds
    // Assuming ~1ns per iteration, need ~10M iterations for 0.01s
    // Use 16M elements to be safe (128KB for 64-bit unsigned long)
    const int data_size = 16 * 1024 * 1024 / sizeof(unsigned long);
    
    d_array = (unsigned long*)calloc(data_size, sizeof(unsigned long));
    
    am.d = d_array;
    am.top = 1000;  // starting point
    am.dmax = data_size;
    am.neg = 0;
    am.flags = 0;
    
    top = 11000;  // ending point - creates 10k iterations
}