#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

long arg1[4];
long arg2[4];
long prod[8];
unsigned long carry;
int i;
int j;
int k;

void init_vars() {
    arg1[0] = 0x12345678;
    arg1[1] = 0x9ABCDEF0;
    arg1[2] = 0x23456789;
    arg1[3] = 0x0BADF00D;

    arg2[0] = 0xCAFEBABE;
    arg2[1] = 0xDEADBEEF;
    arg2[2] = 0xFACEDEAD;
    arg2[3] = 0xBAADF00D;

    for (int idx = 0; idx < 8; idx++) {
        prod[idx] = 0;
    }

    carry = 0;
    i = 0;
    j = 0;
    k = 0;
}