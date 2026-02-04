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
    uint64_t prev_load = 0;
    for (x = 0; x <= size; x += 4) {
        uint64_t current_load = (((const union unaligned_64 *)(&top[x - 1]))->l);
        uint64_t combined = current_load ^ prev_load;
        (((union unaligned_64 *)(&ref_tmp[x]))->l) = combined;
        prev_load = current_load;
    }
}
