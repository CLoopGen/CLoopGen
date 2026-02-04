#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int n;
double two_over_x;
double b_jm1;
double b_j;
double b_jp1;
int j;

void init_vars() {
    n = 10000000;
    two_over_x = 2.0 / 100.0;
    b_jm1 = 1.0;
    b_j = 1.5;
    j = 1;
}