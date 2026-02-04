#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
union __attribute__((packed)) __attribute__((may_alias)) unaligned_32 {
    uint32_t l;
};


extern  uint8_t *header;
extern int size;
extern int x;
extern uint32_t sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with unrolling to access two 32-bit values per iteration
    sum = 0;
    int limit = size - (size % 8); // Ensure we don't go out of bounds
    for (x = 0; x < limit; x += 8) {
        sum += ((const union unaligned_32 *)(&header[x]))->l;
        sum += ((const union unaligned_32 *)(&header[x + 4]))->l;
    }
    // Handle remaining elements
    for (; x < size; x += 4) {
        sum += ((const union unaligned_32 *)(&header[x]))->l;
    }
}
