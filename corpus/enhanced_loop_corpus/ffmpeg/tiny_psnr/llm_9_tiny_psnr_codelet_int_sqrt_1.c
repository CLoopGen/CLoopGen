#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint64_t a;
extern uint64_t ret;
extern uint64_t ret_sq;
extern int s;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (s = 15; s >= 0; s--) {
        uint64_t double_shift = 1ULL << (s * 2);
        uint64_t ret_comp = (ret << s);
        uint64_t b = ret_sq + double_shift + (ret_comp << 1);
        uint64_t alt_b = b + (double_shift >> 1) + (ret_comp >> (64 - s)); // Additional computation to increase intensity
        if (alt_b <= a) {
            ret_sq = alt_b;
            ret += (1ULL << s) | (1ULL << (s + 16)); // More aggressive update
        } else if (b <= a) {
            ret_sq = b;
            ret += 1ULL << s;
        }
    }
}
