#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int npoints;
int *membership;
int i;

void init_vars() {
    npoints = 64 * 1024 * 1024 / sizeof(int);  // ~256 MB of data
    membership = (int*)calloc(npoints, sizeof(int));
    if (!membership) {
        exit(1);
    }
}