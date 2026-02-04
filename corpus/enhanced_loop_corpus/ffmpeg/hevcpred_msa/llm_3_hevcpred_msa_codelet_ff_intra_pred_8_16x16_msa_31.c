#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
union __attribute__((packed)) __attribute__((may_alias)) unaligned_32 {
    uint32_t l;
};


extern int i;
extern uint8_t *top;
extern int top_right_size;
extern uint32_t pix;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Strided memory access with reverse traversal (strided by 4 in descending order)
    int start = (16 - top_right_size - 4);
    for (i = start; i >= 0; i -= 4) {
        uint8_t *ptr = top + 16 + top_right_size + i;
        (((union unaligned_32 *)ptr)->l) = pix;
    }
}
