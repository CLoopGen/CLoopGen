#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int target_flags;
char fixed_regs[53];
char call_used_regs[53];
int i;

void init_vars() {
    // Initialize target_flags to a value that will influence the conditional
    // 33554432 is 2^25, so set bit 25 based on typical benchmarking needs
    // Use a value that ensures both branches are tested across runs if needed
    target_flags = 33554432;  // Ensures the ternary condition evaluates to true

    // Initialize fixed_regs and call_used_regs with non-uniform data
    // Use a seed for reproducibility
    srand(123);
    for (int j = 0; j < 53; j++) {
        fixed_regs[j] = rand() % 256;
        call_used_regs[j] = rand() % 256;
    }

    // Ensure i is initialized properly before use in loop
    i = 0;
}