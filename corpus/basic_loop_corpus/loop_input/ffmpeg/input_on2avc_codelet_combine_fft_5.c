#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int tmp;
int half;
int len2;

void init_vars() {
    len2 = 1 << 20;
    tmp = len2 * 4;
    half = 0;
}