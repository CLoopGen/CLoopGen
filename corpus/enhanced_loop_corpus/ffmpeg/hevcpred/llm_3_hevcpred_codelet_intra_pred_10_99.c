#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
union __attribute__((packed)) __attribute__((may_alias)) unaligned_64 {
    uint64_t l;
};


extern int i;
extern int size;
extern uint16_t *left;
extern uint64_t pix;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive byte-wise traversal using pointer arithmetic on uint8_t view
    // Interpret left as byte array and write pix (8 bytes) consecutively at aligned positions
    // This maintains the same logical writes but changes access pattern to byte-level,
    // advancing by 8 bytes each time (equivalent to 4 uint16_t elements).
    uint8_t* byte_ptr = (uint8_t*)left;
    for (i = 0; i < size * sizeof(uint16_t); i += 8) {
        (*(uint64_t*)(byte_ptr + i)) = pix;
    }
    // Note: Assumes little-endian and proper alignment tolerance via unaligned access semantics.
}
