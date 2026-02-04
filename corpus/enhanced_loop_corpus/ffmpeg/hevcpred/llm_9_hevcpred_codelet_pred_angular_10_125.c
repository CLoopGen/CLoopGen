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



void loop(){
    for (x = 0; x <= size; x += 2) {
        uint64_t val1 = ((const union unaligned_64 *)(&top[x - 1]))->l;
        uint64_t val2 = ((const union unaligned_64 *)(&top[x + 1]))->l;
        ((union unaligned_64 *)(&ref_tmp[x]))->l = val1;
        if (x + 2 <= size) {
            ((union unaligned_64 *)(&ref_tmp[x + 2]))->l = val2;
        }
    }
}
