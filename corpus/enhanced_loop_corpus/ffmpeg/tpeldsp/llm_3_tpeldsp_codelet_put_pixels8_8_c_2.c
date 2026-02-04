#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
union __attribute__((packed)) __attribute__((may_alias)) unaligned_32 {
    uint32_t l;
};


extern uint8_t *block;
extern  uint8_t *pixels;
extern ptrdiff_t line_size;
extern int h;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < h; i++) {
    ptrdiff_t idx = i * line_size;
    *((uint32_t *)(block + idx)) = (((const union unaligned_32 *)(pixels + idx))->l);
    *((uint32_t *)(block + idx + 4)) = (((const union unaligned_32 *)(pixels + idx + 4))->l);
}
}
