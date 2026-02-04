#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
union __attribute__((packed)) __attribute__((may_alias)) unaligned_32 {
    uint32_t l;
};


extern int i;
extern int size;
extern uint8_t *left;
extern uint32_t pix;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int outer = 0; outer < 2; ++outer)
        for (i = outer * size; i < ((outer + 1) * size); i += 4)
            ((((union unaligned_32 *)(left + i))->l) = (pix));
}
