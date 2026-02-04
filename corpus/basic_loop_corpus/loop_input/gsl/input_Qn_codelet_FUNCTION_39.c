#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int ni = 100000;

int *left;
int *right;
int i;
int j;

void init_vars() {
    left = (int*)malloc(ni * sizeof(int));
    right = (int*)malloc(ni * sizeof(int));

    for (int idx = 0; idx < ni; ++idx) {
        left[idx] = 0;
        right[idx] = 10; 
    }

    i = 0;
    j = 0;
}