#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>

size_t transparent_palette_index;
uint32_t *palette;

void init_vars() {
    palette = (uint32_t*)aligned_alloc(64, 256 * sizeof(uint32_t));
    for (int i = 0; i < 256; ++i) {
        palette[i] = ((uint32_t)(i + 1) << 24) | 0xABCDEF;
    }
    // Set one entry to have alpha == 0 to trigger break
    palette[200] = 0x00ABCDEF;
}

__attribute__((destructor))
void cleanup() {
    free(palette);
}