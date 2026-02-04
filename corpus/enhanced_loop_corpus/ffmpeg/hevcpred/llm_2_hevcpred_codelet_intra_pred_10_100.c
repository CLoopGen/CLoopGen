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
    for (i = 0; i < size; i += 8) {
        if (i + 4 < size) {
            (((union unaligned_64 *)(left + size + i))->l) = pix;
        }
        if (i + 6 < size) {
            (((union unaligned_64 *)(left + size + i + 2))->l) = pix;
        }
    }
}
