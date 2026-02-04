#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int y;
int s[10] = {0};

void init_vars() {
    s[0] = 0x12345678;
    s[1] = 0x23456789;
    s[2] = 0x3456789A;
    s[3] = 0x456789AB;
    s[4] = 0x56789ABC;
    s[5] = 0x6789ABCD;
    s[6] = 0x789ABCDE;
    s[7] = 0x89ABCDEF;
    s[8] = 0x9ABCDEF0;
    s[9] = 0xABCDEF01;
    y = 1;
}