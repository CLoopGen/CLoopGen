#include <stdio.h>
#include <inttypes.h>

typedef unsigned long LONG;

int i;
LONG temp;
LONG A = 0x12345678UL;
LONG B = 0x23456789UL;
LONG C = 0x3456789AUL;
LONG D = 0x456789ABUL;
LONG E = 0x56789ABCUL;
LONG W[80];

void init_vars() {
    for (int idx = 0; idx < 80; ++idx) {
        W[idx] = 0xABCDEF00UL + idx;
    }
    i = 0;
    temp = 0;
}