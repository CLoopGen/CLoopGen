#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

unsigned long test_a[10000];
unsigned long test_b[10000];
unsigned long test_c[10000];
unsigned long test_d[10000];
double test_e[10000];
double test_f[10000];
int i;
int status;

void init_vars() {
    for (i = 0; i < 10000; ++i) {
        test_a[i] = i * 2;
        test_b[i] = i * 2;
        test_c[i] = i * 3;
        test_d[i] = i * 3 + 1;
        test_e[i] = i * 0.5;
        test_f[i] = i * 0.5;
    }
    i = 0;
    status = 0;
}