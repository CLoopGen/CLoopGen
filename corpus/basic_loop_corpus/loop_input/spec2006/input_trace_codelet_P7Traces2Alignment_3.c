#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

int mlen = 1048576; // ~1M elements for ~0.01 sec runtime
int *inserts;
int k;

void init_vars() {
    inserts = (int*)calloc(mlen + 1, sizeof(int));
}