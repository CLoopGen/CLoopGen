#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
union __attribute__((packed)) __attribute__((may_alias)) unaligned_64 {
    uint64_t l;
};


extern int64_t *error;
extern int error_count;
extern uint8_t *side_data;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Strided memory access with increased stride (access every other element)
    for (i = 0; i < error_count; i += 2) {
        if (i < error_count) {
            (((union unaligned_64 *)(side_data + 8 + 8 * i))->l) = (error[i]);
        }
    }
}
