#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef unsigned long HARD_REG_ELT_TYPE;

size_t i;
char call_used_regs[53];
char regs_ever_live[53];
HARD_REG_ELT_TYPE regs_used_so_far;

void init_vars() {
    // Initialize arrays to ensure defined behavior
    for (size_t idx = 0; idx < 53; idx++) {
        call_used_regs[idx] = (idx % 7 == 0);  // Sparse pattern to trigger some updates
        regs_ever_live[idx] = (idx % 11 == 0); // Another sparse pattern
    }

    regs_used_so_far = 0;

    // Ensure loop bounds are safe: i is used from 0 to 52, which is within array bounds [53]
}