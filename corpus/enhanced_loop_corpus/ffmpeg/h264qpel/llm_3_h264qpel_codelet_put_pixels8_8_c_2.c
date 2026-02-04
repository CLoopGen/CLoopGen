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
    uint8_t *p = pixels + idx;
    uint8_t *b = block + idx;
    ((union unaligned_32 *)b)->l = ((const union unaligned_32 *)p)->l;
    ((union unaligned_32 *)(b + 4))->l = ((const union unaligned_32 *)(p + 4))->l;
}
}
