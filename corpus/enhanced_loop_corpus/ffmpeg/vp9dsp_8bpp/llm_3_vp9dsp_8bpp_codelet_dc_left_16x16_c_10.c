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

extern ptrdiff_t stride;
extern uint8_t *dst;
extern uint32_t dc;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided access with vertical pattern using array-of-arrays indexing simulation
    uint8_t (*dst_plane)[stride] = (uint8_t (*)[stride])dst;
    for (y = 0; y < 16; y++) {
        ((av_alias32*)&dst_plane[y][ 0])->u32 = dc;
        ((av_alias32*)&dst_plane[y][ 4])->u32 = dc;
        ((av_alias32*)&dst_plane[y][ 8])->u32 = dc;
        ((av_alias32*)&dst_plane[y][12])->u32 = dc;
    }
}
