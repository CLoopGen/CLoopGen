#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
union __attribute__((packed)) __attribute__((may_alias)) unaligned_64 {
    uint64_t l;
};


extern int i;
extern int size;
extern uint16_t *top;
extern uint64_t pix;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < (size); i += 8) { // Increase step to reduce trip count and decouple overlapping stores
        ((((union unaligned_64 *)(top + i))->l) = (pix));
        if (i + 4 < size) {
            ((((union unaligned_64 *)(top + i + 4))->l) = (pix)); // Remove loop-carried dependency by unrolling and removing index recurrence
        }
    }
}
