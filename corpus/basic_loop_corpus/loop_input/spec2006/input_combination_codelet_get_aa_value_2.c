#include <stdint.h>

int aa_values[400];
int stones[361];
int k;
int num_stones;
int value;

void init_vars() {
    // Initialize aa_values with non-zero values to ensure meaningful computation
    for (int i = 0; i < 400; i++) {
        aa_values[i] = (i * 7919) % 123; // Arbitrary prime-based pattern
    }

    // Initialize stones array with valid indices into aa_values (0 to 399)
    for (int i = 0; i < 361; i++) {
        stones[i] = (i * 17) % 400; // Ensure within [0,399]
    }

    // Set num_stones to the full size of stones array since it's safe
    num_stones = 361;

    // Initialize value to zero to start accumulation cleanly
    value = 0;
}