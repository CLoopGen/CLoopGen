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

static unsigned long udp_array[16384];
static unsigned long d_array[1024];

BIGNUM *u;
int i;
int top;
unsigned long *udp;

void init_vars() {
    u = (BIGNUM *)malloc(sizeof(BIGNUM));
    u->d = d_array;
    u->top = 512;
    u->dmax = 1024;
    u->neg = 0;
    u->flags = 0;

    top = 16384;
    udp = udp_array;
}