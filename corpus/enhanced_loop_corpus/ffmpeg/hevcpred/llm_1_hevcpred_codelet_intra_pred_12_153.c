#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
union __attribute__((packed)) __attribute__((may_alias)) unaligned_64 {
    uint64_t l;
};


extern int i;
extern int size;
extern uint16_t *top;
extern uint64_t pix;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int stride = 1; stride <= 2; stride *= 2)
        for (i = 0; i < (2 * size); i += 4 * stride) {
            ((((union unaligned_64 *)(top + i))->l) = (pix));
            if (i + 4 < (2 * size))
                ((((union unaligned_64 *)(top + i + 4))->l) = (pix));
        }
}
