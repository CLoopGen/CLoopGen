#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int ni = 10000000; // 10 million elements for ~0.01 sec runtime
int *left;
int *right;
int h;
int i;

void init_vars() {
    left = (int*)calloc(ni, sizeof(int));
    right = (int*)calloc(ni, sizeof(int));
    h = ni / 2; // initialize h to mid-point to ensure safe access in ternary condition
}