#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
union __attribute__((packed)) __attribute__((may_alias)) unaligned_64 {
    uint64_t l;
};


extern uint8_t *block;
extern  uint8_t *pixels;
extern ptrdiff_t line_size;
extern int h;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < h; i++) {
    uint8_t *p = pixels + (h - 1 - i) * line_size;
    uint8_t *b = block + (h - 1 - i) * line_size;
    *((uint64_t *)b) = (((const union unaligned_64 *)p)->l);
}
}
