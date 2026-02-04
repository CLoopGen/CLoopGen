#include <inttypes.h>

__attribute__((aligned(64))) int indx[32000];

void init_vars() {
    // No additional initialization required beyond zeroing static storage
    // Array is already in global scope and will be default-initialized to zero
}

// The loop function will be defined externally and uses the indx array with size 32000
// The array size matches the loop bound, so no out-of-bounds access occurs
// Each element is assigned a value between 1 and 4 based on (i + 1) % 4 + 1