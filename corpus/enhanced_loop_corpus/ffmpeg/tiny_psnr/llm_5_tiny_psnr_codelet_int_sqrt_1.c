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
        uint64_t shift_val = 1ULL << s;
        uint64_t b = ret_sq + (shift_val << s) + (ret << (s + 1));
        if (b > a) continue;
        ret_sq = b;
        ret += shift_val;
        if (ret_sq >= a) break;
    }
}
