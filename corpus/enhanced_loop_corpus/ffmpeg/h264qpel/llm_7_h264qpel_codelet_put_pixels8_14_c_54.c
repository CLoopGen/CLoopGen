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
    uint8_t *temp_block = block;
    const uint8_t *read_ptr;
    for (i = 0; i < h; i++) {
        read_ptr = pixels + i * line_size;
        uint64_t val1 = ((const union unaligned_64 *)(read_ptr))->l;
        uint64_t val2 = ((const union unaligned_64 *)(read_ptr + 8))->l;
        ((union unaligned_64 *)temp_block)->l = val1;
        ((union unaligned_64 *)(temp_block + 8))->l = val2;
        temp_block += line_size;
    }
}
