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

static unsigned long *udp_data;
static unsigned long *bdp_data;
static unsigned long *p_d_data;
BIGNUM *p;
int i;
int top;
unsigned long *udp;
unsigned long *bdp;
unsigned long u0;
unsigned long u1;
unsigned long b0;
unsigned long b1;
unsigned long mask;

void init_vars() {
    const int data_size = 131072; // ~128KB of data (16384 * 8 bytes per ulong)
    const int array_len = data_size / sizeof(unsigned long);
    
    udp_data = (unsigned long*)calloc(array_len, sizeof(unsigned long));
    bdp_data = (unsigned long*)calloc(array_len, sizeof(unsigned long));
    p_d_data = (unsigned long*)calloc(array_len, sizeof(unsigned long));
    
    if (!udp_data || !bdp_data || !p_d_data) {
        exit(1);
    }
    
    for (int j = 0; j < array_len; j++) {
        udp_data[j] = (unsigned long)(j * 314159UL);
        bdp_data[j] = (unsigned long)(j * 271828UL);
        p_d_data[j] = (unsigned long)(j * 112358UL);
    }
    
    udp = udp_data;
    bdp = bdp_data;
    
    p = (BIGNUM*)malloc(sizeof(BIGNUM));
    if (!p) {
        exit(1);
    }
    
    p->d = p_d_data;
    p->top = array_len;
    p->dmax = array_len;
    p->neg = 0;
    p->flags = 0;
    
    top = array_len - 1;
    
    u0 = udp[0];
    b0 = bdp[0];
    mask = 0xAAAAAAAAAAAAAAAAUL;
}