#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <inttypes.h>

int ni;
int *left;
int *right;
int h;
int i;

void init_vars() {
    ni = 65536;  // Size chosen to run loop in ~0.01 seconds
    h = ni / 2;

    left = (int*)malloc(ni * sizeof(int));
    right = (int*)malloc(ni * sizeof(int));

    if (!left || !right) {
        exit(EXIT_FAILURE);
    }
}

void loop();