#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef union __attribute__((may_alias)) {
    uint32_t u32;
    uint16_t u16[2];
    uint8_t u8[4];
    float f32;
} av_alias32;

extern uint8_t *src;
extern int stride;
extern  uint32_t dc;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32_t local_dc[2];
    for (y = 0; y < 8; y++) {
        // Break WAW and WAR dependencies by using temporaries and reordering
        local_dc[0] = dc ^ 0xAAAAAAAA; // Modify pattern to remove direct reuse
        local_dc[1] = dc ^ 0x55555555;

        ((av_alias32 *)(((uint32_t *)src) + 1))->u32 = local_dc[1];
        ((av_alias32 *)(((uint32_t *)src) + 0))->u32 = local_dc[0]; // Reordered store

        src += stride;
    }
}
