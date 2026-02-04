#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
union __attribute__((packed)) __attribute__((may_alias)) unaligned_32 {
    uint32_t l;
};


extern uint8_t *dst;
extern ptrdiff_t stride;
extern int x;
extern int y;
extern uint32_t colors[4];
extern uint32_t code;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect access via index array to simulate non-sequential pattern (e.g., shuffled x order)
    int indices[4] = {1, 3, 0, 2}; // Arbitrary permutation for indirect access
    uint8_t *d = dst;
    uint32_t local_code = code;
    for (y = 0; y < 4; y++) {
        for (int i = 0; i < 4; i++) {
            x = indices[i]; // Use indirection to access x in non-sequential order
            uint32_t pixel = colors[local_code & 3];
            local_code >>= 2;
            (((union unaligned_32 *)(d + x * 4))->l) = pixel;
        }
        d += stride;
    }
}
