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
    uint64_t pix1 = pix;
    uint64_t pix2 = pix ^ 0xABCDEF0000000000ULL;
    uint64_t pix3 = pix ^ 0x55AA55AA00000000ULL;
    uint64_t pix4 = pix ^ 0xDEADBEEFCAFEBABEULL;
    for (i = 0; i < size; i += 16) {
        if (i + 12 < size) {
            ((((union unaligned_64 *)(top + i + 0))->l) = pix1);
            ((((union unaligned_64 *)(top + i + 4))->l) = pix2);
            ((((union unaligned_64 *)(top + i + 8))->l) = pix3);
            ((((union unaligned_64 *)(top + i + 12))->l) = pix4);
        }
    }
}
