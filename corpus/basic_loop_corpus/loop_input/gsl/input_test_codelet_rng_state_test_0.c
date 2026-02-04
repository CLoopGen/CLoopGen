#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

unsigned long test_a[10000];
unsigned long test_b[10000];
int i;
int status;

void init_vars() {
    for (int idx = 0; idx < 10000; ++idx) {
        test_a[idx] = idx * 2;
        test_b[idx] = idx * 2 + 1;
    }
    i = 0;
    status = 0;
}