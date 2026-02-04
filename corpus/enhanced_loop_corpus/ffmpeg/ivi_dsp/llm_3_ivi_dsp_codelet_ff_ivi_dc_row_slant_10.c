#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *out;
extern ptrdiff_t pitch;
extern int blk_size;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access — write to every other element, then fill in reverse order
    // This changes access pattern to non-sequential and backward in inner loop
    int16_t *base = out + pitch;
    for (y = 1; y < blk_size; y++, base += pitch) {
        int16_t *row = base;
        // First pass: zero even indices
        for (x = 0; x < blk_size; x += 2) {
            row[x] = 0;
        }
        // Second pass: zero odd indices in reverse order (strided + reverse)
        for (x = blk_size - 1; x >= 1; x -= 2) {
            if (x % 2 == 1) row[x] = 0;
        }
    }
}
