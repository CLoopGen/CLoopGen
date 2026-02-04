#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
union __attribute__((packed)) __attribute__((may_alias)) unaligned_32 {
    uint32_t l;
};


extern int size;
extern int x;
extern  uint8_t *left;
extern uint8_t *ref_tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (x = 0; x <= size; x += 2) {
        uint32_t val = ((const union unaligned_32 *)(&left[x - 1]))->l;
        ((union unaligned_32 *)(&ref_tmp[x]))->l = val ^ 0xFFFFFFFFU;
        if (x + 2 <= size) {
            ((union unaligned_32 *)(&ref_tmp[x + 2]))->l = val;
        }
    }
}
