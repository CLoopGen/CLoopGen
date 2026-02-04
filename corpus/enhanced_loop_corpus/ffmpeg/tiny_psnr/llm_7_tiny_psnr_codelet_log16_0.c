#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint64_t exp16_table[21];
extern uint64_t a;
extern int i;
extern int out;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint64_t temp_a = a;
    int temp_out = out;
    for (i = 20; i >= 0; i--) {
        int64_t b = exp16_table[i];
        uint64_t shifted_b = b << 16;
        if (temp_a < shifted_b)
            continue;
        temp_out |= 1 << i;
        uint64_t new_a_high = (temp_a / b) << 16;
        uint64_t new_a_low = (((temp_a % b) << 16) + b / 2) / b;
        temp_a = new_a_high + new_a_low;
    }
    a = temp_a;
    out = temp_out;
}
