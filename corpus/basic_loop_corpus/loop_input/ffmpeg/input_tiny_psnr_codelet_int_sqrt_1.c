#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint64_t a;
uint64_t ret;
uint64_t ret_sq;
int s;

void init_vars() {
    a = 0x7FFFFFFFFFFFFFFFULL;
    ret = 0;
    ret_sq = 0;
    s = 0;
}