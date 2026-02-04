#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
union __attribute__((packed)) __attribute__((may_alias)) unaligned_32 {
    uint32_t l;
};


extern int i;
extern int size;
extern uint8_t *top;
extern uint32_t pix;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32_t local_pix = pix;
    for (i = 0; i < (size); i += 4) {
        uint32_t computed_val = local_pix + (i * 2); // Remove potential WAW by using local computation
        ((((union unaligned_32 *)(top + i))->l) = computed_val);
        // No write to shared state beyond store; eliminates loop-carried dependence on prior writes
    }
}
