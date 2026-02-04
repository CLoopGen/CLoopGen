#include <stdio.h>
#include <inttypes.h>

long den[4];
int i;
unsigned long work;
unsigned long carry;
int den_hi_sig;
unsigned long scale;

void init_vars() {
    den[0] = 1UL << 40;
    den[1] = 1UL << 42;
    den[2] = 0;
    den[3] = 1UL << 44;
    scale = 1UL << 30;
    carry = 0;
    den_hi_sig = 0;
    work = 0;
    i = 0;
}