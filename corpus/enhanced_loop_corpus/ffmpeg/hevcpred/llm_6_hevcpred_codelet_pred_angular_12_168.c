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
    for (x = 1; x <= size - 3; x += 4) {
        uint64_t temp1 = ((const union unaligned_64 *)(&top[x - 1]))->l;
        uint64_t temp2 = ((const union unaligned_64 *)(&top[x + 3 - 1]))->l;
        (((union unaligned_64 *)(&ref_tmp[x]))->l) = temp1;
        (((union unaligned_64 *)(&ref_tmp[x + 2]))->l) = temp2;
    }
}
