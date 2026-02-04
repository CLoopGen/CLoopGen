#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

long aa[10000000];
unsigned int n = 10000000;
unsigned int j = 100;

void init_vars() {
    for (unsigned int i = 0; i < 100; i++) {
        aa[i] = rand() & (((1L << 30) - 1));
    }
    for (unsigned int i = 100; i < n; i++) {
        aa[i] = 0;
    }
}