#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
union __attribute__((packed)) __attribute__((may_alias)) unaligned_64 {
    uint64_t l;
};


extern int i;
extern int size;
extern uint16_t *left;
extern uint64_t pix;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int outer = 0; outer < (size / 4); ++outer) {
        for (int inner = 0; inner < 4; ++inner) {
            int i = outer * 4 + inner;
            if (i < size) {
                (((union unaligned_64 *)(left + i))->l) = (pix);
            }
        }
    }
}
