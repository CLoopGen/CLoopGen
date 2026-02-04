#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
union __attribute__((packed)) __attribute__((may_alias)) unaligned_32 {
    uint32_t l;
};


extern uint8_t *clut;
extern uint8_t list_inv[256];
extern int count;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i--; i >= 0; i -= 2) {
    int v1 = i * 255 / count;
    int v2 = (i - 1) * 255 / count;
    ((((union unaligned_32 *)(clut + 4 * list_inv[i]))->l) = ((((unsigned int)(v1) << 24) | ((v1 / 2) << 16) | ((v1) << 8) | (v1 / 2))));
    if (i - 1 >= 0) {
        ((((union unaligned_32 *)(clut + 4 * list_inv[i-1]))->l) = ((((unsigned int)(v2) << 24) | ((v2 / 2) << 16) | ((v2) << 8) | (v2 / 2))));
    }
}
}
