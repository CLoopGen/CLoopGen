#include <stdio.h>

#include <inttypes.h>

extern uint64_t x;
extern uint64_t r;
extern uint64_t b;
extern int s;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    uint64_t temp_r = r;
    for (s = 63; s >= 0; s -= 3) {
        temp_r <<= 1;
        uint64_t b_val = 3 * temp_r * (temp_r + 1) + 1;
        uint64_t x_shifted = x >> s;
        if (x_shifted >= b_val) {
            x -= b_val << s;
            temp_r++;
        }
    }
    r = temp_r;
}
