#include <stdio.h>
#include <inttypes.h>

char regs_ever_live[53];
int i;

void init_vars() {
    for (int idx = 0; idx < 53; idx++) {
        regs_ever_live[idx] = 0;
    }
    // Ensure the loop breaks at the last possible iteration to control runtime
    // The loop runs from i=8 to i=15 (inclusive), so set element 15 to non-zero if within bounds
    if (15 < 53) {
        regs_ever_live[15] = 1;
    }
    i = 0; // Will be set to 8 at start of loop
}