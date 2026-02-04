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

BIGNUM *a;
unsigned long w;
unsigned long ret;
int i;

static unsigned long *data_array;
static BIGNUM a_storage;

void init_vars() {
    const int num_elements = 8192;
    
    data_array = (unsigned long *)malloc(num_elements * sizeof(unsigned long));
    if (!data_array) {
        exit(1);
    }
    
    for (int j = 0; j < num_elements; j++) {
        data_array[j] = (unsigned long)(j * 0xdeadbeefUL + 0x12345678UL);
    }

    a_storage.d = data_array;
    a_storage.top = num_elements;
    a_storage.dmax = num_elements;
    a_storage.neg = 0;
    a_storage.flags = 0;

    a = &a_storage;
    
    w = 987654321UL;
    ret = 123456789UL;
}