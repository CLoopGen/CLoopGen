#include <stdlib.h>
#include <stdint.h>

int *x;
int i;

void init_vars() {
    const size_t data_size = 256 * 1024 * 1024; // 256 MB
    static int x_data[64]; // Array of size 64 to match loop bounds (i < 64)

    // Initialize x to point to the static array
    x = x_data;

    // Initialize array elements to non-zero values for meaningful computation
    for (int j = 0; j < 64; ++j) {
        x[j] = j + 1;
    }
}