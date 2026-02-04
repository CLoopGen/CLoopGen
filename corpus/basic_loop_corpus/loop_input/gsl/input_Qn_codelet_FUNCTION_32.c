#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int ni = 10000000;  // ~10M elements for ~0.01 sec runtime
int h;
int i;
int *left;
int *right;

void init_vars() {
    h = ni / 2;

    left = (int*)malloc(ni * sizeof(int));
    right = (int*)malloc(ni * sizeof(int));

    if (!left || !right) {
        exit(1);
    }
}