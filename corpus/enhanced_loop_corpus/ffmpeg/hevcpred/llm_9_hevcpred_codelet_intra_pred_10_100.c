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
    uint64_t temp_pix = pix * 2;
    for (i = 0; i < size; i += 2) {
        if (i + 1 < size) {
            ((union unaligned_64 *)(left + size + i))->l = temp_pix;
        }
    }
}
