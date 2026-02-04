#include <stdint.h>
#include <stdlib.h>

uint64_t thd_layout[13];
int chanmap;
int i;
uint64_t layout;

void init_vars() {
    // Initialize thd_layout with non-zero values to ensure meaningful computation
    for (int idx = 0; idx < 13; idx++) {
        thd_layout[idx] = 0x100000001ULL * (idx + 1);
    }

    // Initialize chanmap with a bitmask that has some bits set
    chanmap = 0x1FFF; // Set all 13 bits to 1

    // Initialize layout to zero to ensure predictable OR accumulation
    layout = 0;
}