#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t i;
extern  int16_t *filter_ptr1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t i;
    int16_t *local_ptr = filter_ptr1;
    for (i = 0; i < 8; i++) {
        // Variant 1: Consecutive memory access with increment of 1
        // Instead of jumping by 8, traverse consecutive locations
        local_ptr += 1;
    }
    filter_ptr1 = local_ptr; // Update global pointer
}
