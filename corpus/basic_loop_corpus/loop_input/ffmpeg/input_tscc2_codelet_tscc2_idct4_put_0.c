#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int *in;
int q[3];
int i;
int tblk[16];
int t0;
int t1;
int t2;
int t3;

void init_vars() {
    const size_t input_size = 1024 * 1024; // ~1MB to target ~0.01s runtime
    int *in_data = (int*)calloc(input_size, sizeof(int));
    in = in_data;

    // Initialize q array (size 3 as declared)
    q[0] = 17;
    q[1] = 31;
    q[2] = 64;

    // Initialize tblk to zero
    for (int j = 0; j < 16; j++) {
        tblk[j] = 0;
    }

    // Initialize temporaries
    t0 = 0;
    t1 = 0;
    t2 = 0;
    t3 = 0;
    i = 0;

    // Ensure input data has valid values for 4x4 access pattern
    for (int row = 0; row < 4; row++) {
        for (int col = 0; col < 4; col++) {
            in[row * 4 + col] = (row + 1) * 10 + (col + 1);
        }
    }
}