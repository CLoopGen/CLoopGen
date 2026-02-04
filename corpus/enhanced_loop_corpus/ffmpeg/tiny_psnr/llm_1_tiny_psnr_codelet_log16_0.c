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
    // Outer loop controlling coarse iteration, split original range into two parts
    for (int part = 1; part >= 0; part--) {
        int start = (part == 1) ? 20 : 10;
        int end = (part == 1) ? 11 : 0;
        for (i = start; i >= end; i--) {
            int64_t b = exp16_table[i];
            if (a < (b << 16))
                continue;
            out |= 1 << i;
            a = ((a / b) << 16) + (((a % b) << 16) + b / 2) / b;
        }
    }
}
