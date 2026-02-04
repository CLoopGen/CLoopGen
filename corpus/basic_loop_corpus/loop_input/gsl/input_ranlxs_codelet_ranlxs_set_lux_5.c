#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int i;
int k;
int xbit[31];

void init_vars() {
    i = 123456789;
    k = 0;
    for (int idx = 0; idx < 31; ++idx) {
        xbit[idx] = 0;
    }
}