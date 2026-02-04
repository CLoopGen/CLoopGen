#include <stdio.h>
#include <inttypes.h>

long mhigh_hi;
long mlow_hi;
unsigned long mhigh_lo;
unsigned long mlow_lo;
int lgup;
int post_shift;

void init_vars() {
    mhigh_hi = 0x7FFFFFFFFFFF0000L;
    mlow_hi = 0x8000000000000000L;
    mhigh_lo = 0xFFFFFFFFFFFFFFFFUL;
    mlow_lo = 0x0000000000000001UL;
    lgup = 64;
}