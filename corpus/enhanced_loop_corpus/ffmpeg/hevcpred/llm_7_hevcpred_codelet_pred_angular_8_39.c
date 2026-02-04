#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
union __attribute__((packed)) __attribute__((may_alias)) unaligned_32 {
    uint32_t l;
};


extern int size;
extern int x;
extern  uint8_t *top;
extern uint8_t *ref_tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    for (x = 4; x <= size + 4; x += 4) {
        (((union unaligned_32 *)(&ref_tmp[x - 4]))->l) = ((((const union unaligned_32 *)(&top[x - 5]))->l));
    }
}
