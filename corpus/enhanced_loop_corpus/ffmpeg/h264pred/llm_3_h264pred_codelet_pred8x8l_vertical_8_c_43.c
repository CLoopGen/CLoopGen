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

extern int y;
extern uint8_t *src;
extern int stride;
extern uint32_t a;
extern uint32_t b;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided access with increasing stride multiplier (simulating non-unit stride over larger blocks)
    int effective_stride = stride * 2; // Access every other row effectively
    for (y = 1; y < 8; y += 2) { // Step by 2 to emphasize strided pattern
        uint8_t *row = src + y * effective_stride;
        ((av_alias32*)(((uint32_t*)row) + 0))->u32 = a;
        ((av_alias32*)(((uint32_t*)row) + 1))->u32 = b;
        // Add intermediate access to simulate irregular but predictable pattern
        if (y + 1 < 8) {
            uint8_t *next_row = src + (y + 1) * effective_stride;
            ((av_alias32*)(((uint32_t*)next_row) + 0))->u32 = b;
            ((av_alias32*)(((uint32_t*)next_row) + 1))->u32 = a;
        }
    }
}
