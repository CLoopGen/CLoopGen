#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int ni;
int *left;
int *right;
int h;
int i;

void init_vars() {
    ni = 65536; // Approximate size for ~0.01 sec runtime
    h = ni / 2;

    left = (int*)malloc(ni * sizeof(int));
    right = (int*)malloc(ni * sizeof(int));

    if (!left || !right) {
        exit(1);
    }
}

void loop();

// Ensure linkage with external loop function