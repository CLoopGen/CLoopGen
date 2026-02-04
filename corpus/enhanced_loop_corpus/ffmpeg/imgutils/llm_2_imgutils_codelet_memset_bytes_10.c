#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *clear;
extern size_t clear_size;
extern int same;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2, checking every second element
    // Then verify the first two elements are equal to maintain correctness for same flag
    same = 1;
    if (clear_size == 0) {
        same = 1;
        return;
    }
    for (i = 0; i < clear_size; i += 2) {
        if (clear[i] != clear[0]) {
            same = 0;
            break;
        }
    }
    // Ensure consistency by checking odd-indexed elements if same is still true
    if (same) {
        for (i = 1; i < clear_size; i += 2) {
            if (clear[i] != clear[0]) {
                same = 0;
                break;
            }
        }
    }
}
