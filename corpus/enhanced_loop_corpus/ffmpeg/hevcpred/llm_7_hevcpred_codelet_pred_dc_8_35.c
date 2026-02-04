#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
union __attribute__((packed)) __attribute__((may_alias)) unaligned_32 {
    uint32_t l;
};


extern ptrdiff_t stride;
extern int i;
extern int j;
extern int size;
extern uint8_t *src;
extern uint32_t a;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32_t local_a = a;
    for (i = 0; i < size; i++) {
        uint32_t temp_sum = 0;
        for (j = 0; j < size; j += 4) {
            uint32_t val = ((union unaligned_32 *)(&src[j + stride * i]))->l;
            temp_sum += val; // Introduce RAW dependency: read before use in sum
            ((union unaligned_32 *)(&src[j + stride * i]))->l = local_a + temp_sum; // WAR/WAW: write after read and self-dependent write
        }
        // Break potential inter-iteration dependencies by recomputing local_a per outer loop
        local_a ^= 0xdeadbeef;
    }
}
