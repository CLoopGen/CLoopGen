#include <stdio.h>
#include <inttypes.h>

unsigned long h = 1234567890UL;
unsigned long l = 9876543210UL;
unsigned long d = 1000000007UL;
unsigned long dh = 500000003UL;
unsigned long dl = 200000001UL;
unsigned long q = 0UL;
unsigned long ret = 0UL;
unsigned long th = 0UL;
unsigned long tl = 0UL;
unsigned long t = 0UL;
int count = 50000;

void init_vars(void) {
    h = 1234567890UL;
    l = 9876543210UL;
    d = 1000000007UL;
    dh = 500000003UL;
    dl = 200000001UL;
    q = 0UL;
    ret = 0UL;
    th = 0UL;
    tl = 0UL;
    t = 0UL;
    count = 50000;
}