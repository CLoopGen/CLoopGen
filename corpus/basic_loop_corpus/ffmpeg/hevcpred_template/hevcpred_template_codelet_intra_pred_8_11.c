#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
union __attribute__((packed)) __attribute__((may_alias)) unaligned_32 {
    uint32_t l;
};


extern int i;
extern uint8_t *left;
extern int size_max_y;
extern uint32_t pix;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (i = 0; i < (size_max_y); i += 4)
    ((((union unaligned_32 *)(left + i))->l) = (pix));

}
