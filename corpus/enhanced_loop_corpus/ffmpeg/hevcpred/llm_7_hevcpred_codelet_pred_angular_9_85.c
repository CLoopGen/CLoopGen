#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
union __attribute__((packed)) __attribute__((may_alias)) unaligned_64 {
    uint64_t l;
};


extern int size;
extern int x;
extern  uint16_t *left;
extern uint16_t *ref_tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    uint64_t prev_load = 0;
    for (x = 0; x <= size; x += 4) {
        if (x == 0) {
            prev_load = ((const union unaligned_64 *)(&left[x - 1]))->l;
        } else {
            (((union unaligned_64 *)(&ref_tmp[x - 4]))->l) = prev_load;
            prev_load = ((const union unaligned_64 *)(&left[x - 1]))->l;
        }
    }
    if (x >= 4) {
        (((union unaligned_64 *)(&ref_tmp[x - 4]))->l) = prev_load;
    }
}
