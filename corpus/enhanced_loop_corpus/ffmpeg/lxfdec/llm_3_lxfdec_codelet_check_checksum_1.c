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
    // Variant 2: Strided memory access — access every 8th byte, forming 32-bit words from strided locations
    sum = 0;
    int stride = 8; // Increased stride for non-consecutive access
    int aligned_size = (size / stride) * stride;
    for (x = 0; x < aligned_size; x += stride) {
        sum += ((const union unaligned_32 *)(&header[x]))->l;
    }
    // Fallback for any leftover bytes if needed, using original step
    for (; x + 4 <= size; x += 4) {
        sum += ((const union unaligned_32 *)(&header[x]))->l;
    }
}
