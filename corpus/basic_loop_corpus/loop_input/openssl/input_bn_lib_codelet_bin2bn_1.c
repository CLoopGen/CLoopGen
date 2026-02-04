#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <inttypes.h>

struct bignum_st {
    unsigned long *d;
    int top;
    int dmax;
    int neg;
    int flags;
};

typedef struct bignum_st BIGNUM;

unsigned char *s;
int len;
BIGNUM *ret;
int inc;
int xor;
int carry;
unsigned int i;
unsigned int n;

void init_vars() {
    const size_t input_size = 1024 * 128; // 128KB of data

    s = (unsigned char *)malloc(input_size);
    if (!s) {
        fprintf(stderr, "Failed to allocate memory for s\n");
        exit(1);
    }

    memset(s, 0x5A, input_size); // Initialize with non-zero pattern

    inc = 1;
    xor = 0x55;
    carry = 0;
    i = 0;

    n = input_size / 8; 
    if (n == 0) n = 1;
    
    len = input_size;

    ret = (BIGNUM *)malloc(sizeof(BIGNUM));
    if (!ret) {
        fprintf(stderr, "Failed to allocate memory for ret\n");
        exit(1);
    }

    ret->dmax = n;
    ret->top = 0;
    ret->neg = 0;
    ret->flags = 0;

    ret->d = (unsigned long *)calloc(n, sizeof(unsigned long));
    if (!ret->d) {
        fprintf(stderr, "Failed to allocate memory for ret->d\n");
        exit(1);
    }
}