#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

int nc;
int *nmem;
int i;

void init_vars() {
    nc = 64 * 1024 * 1024 / sizeof(int);  // ~256MB of data to target ~0.01s on modern CPU
    nmem = (int*)calloc(nc, sizeof(int));
    if (!nmem) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
}