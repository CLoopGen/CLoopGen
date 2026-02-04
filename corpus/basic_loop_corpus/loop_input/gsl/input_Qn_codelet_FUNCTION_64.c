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
    ni = 65536; // Size chosen to be ~256KB of data (65536 * 4 bytes * 2 arrays)
    h = ni / 2;
    
    left = (int*)aligned_alloc(32, ni * sizeof(int));
    right = (int*)aligned_alloc(32, ni * sizeof(int));

    for (int idx = 0; idx < ni; ++idx) {
        left[idx] = 0;
        right[idx] = 0;
    }
}