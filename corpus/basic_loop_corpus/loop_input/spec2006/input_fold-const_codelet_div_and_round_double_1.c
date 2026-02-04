#include <inttypes.h>

long num[5] = {0};
long quo[4] = {0};
int i = 0;
unsigned long work = 0;
unsigned long carry = 0;
unsigned long lden = 1;

void init_vars() {
    num[0] = 1UL << 30;
    num[1] = 1UL << 31;
    num[2] = 1UL << 32;
    num[3] = 1UL << 33;
    num[4] = 1UL << 34;
    lden = (1UL << 32) + 1;
    carry = 1UL << 30;
}