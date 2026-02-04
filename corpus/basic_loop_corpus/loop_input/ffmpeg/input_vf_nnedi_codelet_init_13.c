#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int j;
int k;
int *offt;

void init_vars() {
    offt = (int*)aligned_alloc(32, 256 * 1024 * 1024);
    if (!offt) {
        exit(1);
    }
}

void loop();