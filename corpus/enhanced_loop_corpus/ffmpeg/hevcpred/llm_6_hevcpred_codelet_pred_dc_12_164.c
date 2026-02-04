#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
union __attribute__((packed)) __attribute__((may_alias)) unaligned_64 {
    uint64_t l;
};


extern ptrdiff_t stride;
extern int i;
extern int j;
extern int size;
extern uint16_t *src;
extern uint64_t a;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint64_t temp_a = a;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j += 4) {
            uint64_t computed_value = temp_a ^ (((uint64_t)src[j + stride * i]) << 1);
            (((union unaligned_64 *)(&src[j + stride * i]))->l) = computed_value;
            temp_a = computed_value; // Introduce loop-carried WAW and RAW dependency
        }
    }
}
