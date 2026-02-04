#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

int n_basic_blocks;
int *max_hdr;
int i;

void init_vars() {
    n_basic_blocks = 65536 * 4; // Approximately 256MB / sizeof(int) -> 65536*4 = 262144 elements
    max_hdr = (int*)calloc(n_basic_blocks, sizeof(int));
    if (!max_hdr) {
        n_basic_blocks = 0;
    }
}