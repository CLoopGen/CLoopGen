#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int err;
int i;
char buf[1024];

void init_vars() {
    err = 1;
    i = 0;
    for (int j = 0; j < 1024; ++j) {
        buf[j] = '1';
    }
}