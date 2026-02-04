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
        uint64_t accumulator = 0;
        for (j = 0; j < size; j += 4) {
            accumulator ^= temp_a;
            ((((union unaligned_64 *)(&src[(j) + stride * (i)]))->l) = (accumulator));
        }
        temp_a = accumulator; // Introduce loop-carried dependency across rows
    }
}
