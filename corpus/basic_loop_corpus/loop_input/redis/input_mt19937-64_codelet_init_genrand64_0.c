#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

unsigned long long mt[312];
int mti;

void init_vars() {
    mt[0] = 123456789ULL;
    for (int i = 1; i < 312; i++) {
        mt[i] = 0ULL;
    }
    mti = 1;
}