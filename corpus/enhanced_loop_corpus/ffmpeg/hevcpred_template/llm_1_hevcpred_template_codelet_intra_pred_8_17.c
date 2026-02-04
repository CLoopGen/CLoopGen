#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
union __attribute__((packed)) __attribute__((may_alias)) unaligned_32 {
    uint32_t l;
};


extern int i;
extern int size;
extern uint8_t *top;
extern uint32_t pix;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < (size); i += 8)
        for (int inner = 0; inner < 2; ++inner)
            if (i + 4 * inner < size)
                ((((union unaligned_32 *)(top + i + 4 * inner))->l) = (pix));
}
