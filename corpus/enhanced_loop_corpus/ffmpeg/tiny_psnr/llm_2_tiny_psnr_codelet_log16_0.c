#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint64_t exp16_table[21];
extern uint64_t a;
extern int i;
extern int out;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Strided memory access with reverse stride (access every 2nd element in descending order)
    for (i = 20; i >= 0; i -= 2) {
        int64_t b = exp16_table[i];
        if (a < (b << 16))
            continue;
        out |= 1 << i;
        a = ((a / b) << 16) + (((a % b) << 16) + b / 2) / b;
        // Handle potential odd index wrap-around to maintain coverage
        if (i == 1) {
            i = 0; // Ensure index 0 is processed after 2
            int64_t b_next = exp16_table[i];
            if (a >= (b_next << 16)) {
                out |= 1 << i;
                a = ((a / b_next) << 16) + (((a % b_next) << 16) + b_next / 2) / b_next;
            }
        }
    }
}
