#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t bitalloc_12_bits[5][12];
extern int *values;
extern uint8_t n;
extern uint8_t sel;
extern uint8_t i;
extern uint8_t id;
extern uint32_t sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided Memory Access Pattern
    // Instead of accessing bitalloc_12_bits[sel][id] with id derived sequentially from values[i],
    // we access the array with a stride of 2 over the values array, handling bounds safely.
    uint8_t stride = 2;
    sum = 0; // Reset sum as in typical usage
    for (i = 0; i < n; i += stride) {
        if (values[i] >= 1 && values[i] <= 12) { // Ensure valid index range
            id = values[i] - 1;
            sum += bitalloc_12_bits[sel][id];
        }
    }
}
