#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
union __attribute__((packed)) __attribute__((may_alias)) unaligned_64 {
    uint64_t l;
};


extern int size;
extern int x;
extern  uint16_t *top;
extern uint16_t *ref_tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Consecutive (sequential) memory access using a forward-copying pattern with byte granularity simulation via uint64_t
    // Simulate overlapping aligned 64-bit loads/stores by shifting index progressively
    for (x = 0; x <= size - 3; x += 1) {
        // Copy one aligned 64-bit block at a time from top[x-1] to ref_tmp[x], moving forward consecutively
        (((union unaligned_64 *)(&ref_tmp[x]))->l) = (((const union unaligned_64 *)(&top[x - 1]))->l);
    }
    // Handle final alignment if needed, assuming size allows partial
    if (x <= size) {
        (((union unaligned_64 *)(&ref_tmp[x]))->l) = (((const union unaligned_64 *)(&top[x - 1]))->l);
    }
}
