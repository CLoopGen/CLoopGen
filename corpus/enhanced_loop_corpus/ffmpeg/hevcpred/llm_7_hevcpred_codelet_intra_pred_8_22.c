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
    uint32_t local_pix __attribute__((unused)) = pix;
    for (i = 0; i < (size); i += 4) {
        uint32_t independent_val = ((uint32_t)top[i]) + ((uint32_t)top[i+1]) << 8 // Remove WAW and RAW dependencies by using local, independent computation
                                   + ((uint32_t)top[i+2]) << 16 + ((uint32_t)top[i+3]) << 24;
        independent_val ^= local_pix;
        ((((union unaligned_32 *)(top + i))->l) = independent_val);
    }
}
