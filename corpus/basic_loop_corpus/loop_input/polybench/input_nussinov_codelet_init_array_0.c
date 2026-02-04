#include <stdio.h>
#include <inttypes.h>

typedef char base;

int n = 64000000; // Adjusted to process ~64M elements for ~0.01 sec runtime
base seq[2500]; // Original declared size is 2500, so we respect that
int i;

void init_vars() {
    n = 2500; // Adjust n to prevent out-of-bounds access given seq[2500]
}