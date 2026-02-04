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
    int temp[256]; // Local buffer to store intermediate values and break direct memory dependency
    for (i--; i >= 0; i--) {
        int v = i * 255 / count;
        temp[i] = (((unsigned int)(v) << 24) | ((v / 2) << 16) | ((v) << 8) | (v / 2));
    }
    // Second loop to write data, eliminating WAW and WAR dependencies in original
    for (i--; i >= 0; i--) {
        ((((union unaligned_32 *)(clut + 4 * list_inv[i]))->l) = temp[i]);
    }
}
