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
    for (s = 31; s >= 0; s--) {
        uint64_t shift_val = 1ULL << (s * 2);
        uint64_t ret_shift = ret << s;
        uint64_t b = ret_sq + shift_val + (ret_shift << 1);
        if (b <= a) {
            ret_sq = b;
            ret += 1ULL << s;
        }
    }
}
