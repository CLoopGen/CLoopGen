#include <stdio.h>

#include <inttypes.h>

extern uint64_t x;
extern uint64_t r;
extern uint64_t b;
extern int s;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    uint64_t local_r = r;
    uint64_t prev_b = 0;
    for (s = 63; s >= 0; s -= 3) {
        local_r <<= 1;
        uint64_t b_val = 3 * local_r * (local_r + 1) + 1;
        uint64_t adjusted_b = (prev_b == 0) ? b_val : (b_val + (prev_b >> 1));
        if ((x >> s) >= adjusted_b) {
            x -= adjusted_b << s;
            local_r++;
        }
        prev_b = b_val;
    }
    r = local_r;
}
