#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

char dbuf[5152];
int dlen;
int digits;
int start;

void init_vars() {
    dlen = 123456789;
    digits = 9;
    start = 0;

    for (int i = 0; i < 5152; ++i) {
        dbuf[i] = ' ';
    }
}