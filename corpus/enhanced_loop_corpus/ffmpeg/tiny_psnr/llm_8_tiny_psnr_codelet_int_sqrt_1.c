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
    for (s = 31; s >= 0; s -= 2) {
        uint64_t shift_val = 1ULL << (s * 2);
        uint64_t ret_shift = ret << s;
        uint64_t b1 = ret_sq + shift_val + (ret_shift << 1);
        if (b1 <= a) {
            ret_sq = b1;
            ret += 1ULL << s;
        }
        if (s > 0) {
            uint64_t shift_val2 = 1ULL << ((s-1) * 2);
            uint64_t ret_shift2 = ret << (s-1);
            uint64_t b2 = ret_sq + shift_val2 + (ret_shift2 << 1);
            if (b2 <= a) {
                ret_sq = b2;
                ret += 1ULL << (s-1);
            }
        }
    }
}
