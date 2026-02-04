#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef short IDWTELEM;

extern IDWTELEM *buf;
extern int mb_y;
extern int x;
extern int y;
extern int block_h;
extern int w;
extern int h;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Consecutive (Linearized) Memory Access Pattern
    // Flatten the 2D index space into a single loop over consecutive memory locations.
    // This improves spatial locality and enables better vectorization.
    int start_offset = (block_h * mb_y) * w;
    int end_y = (h > block_h * (mb_y + 1)) ? block_h * (mb_y + 1) : h;
    int end_offset = end_y * w;
    int offset;

    for (offset = start_offset; offset < end_offset; offset++) {
        buf[offset] -= 128 << 4;
    }
}
