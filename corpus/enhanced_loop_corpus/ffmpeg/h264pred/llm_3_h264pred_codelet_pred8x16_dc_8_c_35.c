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
extern int i;
extern uint32_t dc6splat;
extern uint32_t dc7splat;
extern uint8_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided access with reversed iteration order and fixed offset stepping
    for (i = 15; i >= 12; i--) {
        uint8_t *ptr = src + i * stride;
        uint32_t *aligned_row = (uint32_t *)ptr;
        av_alias32 *alias_ptr = (av_alias32 *)aligned_row;
        alias_ptr[0].u32 = dc6splat;
        alias_ptr[1].u32 = dc7splat;
    }
}
