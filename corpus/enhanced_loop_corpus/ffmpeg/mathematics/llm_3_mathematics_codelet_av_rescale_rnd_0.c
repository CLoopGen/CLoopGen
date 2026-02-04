#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int64_t c;
extern uint64_t a0;
extern uint64_t a1;
extern uint64_t t1;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Memory Access Pattern Modification using indirect access via index mapping
    // Use an auxiliary array to define an indirect order of bit access (e.g., reverse bit order)
    static const int indices[64] = {
        0, 32, 16, 48, 8, 40, 24, 56,
        4, 36, 20, 52, 12, 44, 28, 60,
        2, 34, 18, 50, 10, 42, 26, 58,
        6, 38, 22, 54, 14, 46, 30, 62,
        1, 33, 17, 49, 9, 41, 25, 57,
        5, 37, 21, 53, 11, 45, 29, 59,
        3, 35, 19, 51, 13, 47, 31, 61,
        7, 39, 23, 55, 15, 48, 32, 63
    };
    uint64_t temp_a0 = a0;
    for (i = 0; i < 64; i++) {
        int bit_pos = indices[i];  // Indirect access through lookup table
        a1 += a1 + ((temp_a0 >> bit_pos) & 1);
        t1 += t1;
        if (c <= a1) {
            a1 -= c;
            t1++;
        }
    }
}
