#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
union __attribute__((packed)) __attribute__((may_alias)) unaligned_16 {
    uint16_t l;
};


extern uint8_t *dst;
extern int dx;
extern int w;
extern unsigned int asrc;
extern unsigned int tau;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t *temp_dst = dst;
    uint16_t prev_value = 0;
    int has_prev = 0;
    for (x = 0; x < w; x++) {
        uint16_t value = (((const union unaligned_16 *)(temp_dst))->l);
        uint16_t computed = (value * tau + asrc) >> 16;
        if (has_prev) {
            computed = (computed + prev_value) >> 1; // Introduce WAW and loop-carried dependency
        }
        ((((union unaligned_16 *)(temp_dst))->l) = computed);
        prev_value = computed;
        has_prev = 1;
        temp_dst += dx;
    }
}
