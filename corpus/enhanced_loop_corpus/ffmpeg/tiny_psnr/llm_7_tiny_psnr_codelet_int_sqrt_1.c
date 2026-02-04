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
    uint64_t temp_ret = ret;
    uint64_t temp_ret_sq = ret_sq;
    for (s = 31; s >= 0; s--) {
        uint64_t shifted = 1ULL << s;
        uint64_t candidate_ret = temp_ret + shifted;
        uint64_t b = temp_ret_sq + (1ULL << (s * 2)) + (temp_ret << s) * 2;
        if (b <= a) {
            temp_ret_sq = b;
            temp_ret = candidate_ret;
        }
    }
    ret = temp_ret;
    ret_sq = temp_ret_sq;
}
