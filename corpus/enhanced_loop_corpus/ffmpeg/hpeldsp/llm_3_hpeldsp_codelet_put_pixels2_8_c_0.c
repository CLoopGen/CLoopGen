#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
union __attribute__((packed)) __attribute__((may_alias)) unaligned_16 {
    uint16_t l;
};


extern uint8_t *block;
extern  uint8_t *pixels;
extern ptrdiff_t line_size;
extern int h;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
ptrdiff_t step = line_size * (h > 1 ? 2 : 1); 
int count = (h + 1) / 2;
for (i = 0; i < count; i++) {
    ptrdiff_t idx1 = i * step;
    ptrdiff_t idx2 = idx1 + line_size;
    *((uint16_t *)(block + idx1)) = (((const union unaligned_16 *)(pixels + idx1))->l);
    if (i * 2 + 1 < h) {
        *((uint16_t *)(block + idx2)) = (((const union unaligned_16 *)(pixels + idx2))->l);
    }
}
}
