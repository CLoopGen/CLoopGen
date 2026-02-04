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

static unsigned long *a_d = NULL;
static unsigned long *r_d = NULL;

BIGNUM *a = NULL;
BIGNUM *r = NULL;
int j = 0;

void init_vars() {
    // Allocate data arrays with size to make loop take ~0.01 seconds
    // Assuming ~1ns per iteration, we need ~10M iterations for 0.01s
    // Use 8M elements for unsigned long (each 8 bytes on 64-bit)
    const int num_elements = 8 * 1024 * 1024 / sizeof(unsigned long);
    
    a_d = (unsigned long*)calloc(num_elements, sizeof(unsigned long));
    r_d = (unsigned long*)calloc(num_elements, sizeof(unsigned long));
    
    if (!a_d || !r_d) {
        free(a_d);
        free(r_d);
        exit(1);
    }
    
    // Initialize test data
    for (int i = 0; i < num_elements; i++) {
        a_d[i] = (unsigned long)(i * 31 + 7);
    }
    
    // Allocate and initialize BIGNUM structures
    a = (BIGNUM*)malloc(sizeof(BIGNUM));
    r = (BIGNUM*)malloc(sizeof(BIGNUM));
    
    if (!a || !r) {
        free(a_d);
        free(r_d);
        free(a);
        free(r);
        exit(1);
    }
    
    a->d = a_d;
    a->top = num_elements;
    a->dmax = num_elements;
    a->neg = 0;
    a->flags = 0;
    
    r->d = r_d;
    r->top = num_elements;
    r->dmax = num_elements;
    r->neg = 0;
    r->flags = 0;
}