#include <stdio.h>
#include <inttypes.h>

typedef unsigned long LONG;

int i;
LONG W[80];

void init_vars() {
    for (int j = 0; j < 16; ++j) {
        W[j] = j + 1;
    }
    for (int j = 16; j < 80; ++j) {
        W[j] = 0;
    }
    i = 0;
}