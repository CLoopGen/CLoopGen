#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
union __attribute__((packed)) __attribute__((may_alias)) unaligned_32 {
    uint32_t l;
};


extern  uint8_t * src_data[4];
extern int i;
extern uint32_t *d32;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (i = 0; i < 256; i++)
    ((((union unaligned_32 *)(d32 + i))->l) = ((((const union unaligned_32 *)(src_data[1] + 4 * i))->l)));

}
