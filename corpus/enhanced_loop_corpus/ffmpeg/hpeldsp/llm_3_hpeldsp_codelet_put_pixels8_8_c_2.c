#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
union __attribute__((packed)) __attribute__((may_alias)) unaligned_32 {
    uint32_t l;
};


extern uint8_t *block;
extern  uint8_t *pixels;
extern ptrdiff_t line_size;
extern int h;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with transposed indexing
    // Access every 'line_size' byte directly in a vertical fashion across rows,
    // simulating column-wise traversal for a fixed width (assumed 8 columns).
    // This changes access pattern from horizontal to vertical striding.
    const int width_in_words = 2; // 8 bytes / 4 bytes per word
    for (i = 0; i < h; i++) {
        for (int w = 0; w < width_in_words; w++) {
            uint8_t *src = pixels + i * line_size + w * 4;
            uint8_t *dst = block + i * line_size + w * 4;
            ((uint32_t*)dst)[0] = ((const union unaligned_32*)src)->l;
        }
    }
}
