#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct _PESColorInfo {
    const unsigned char red;
    const unsigned char green;
    const unsigned char blue;
    const unsigned char alpha;
} PESColorInfo;

typedef struct _PESBlockInfo {
    const PESColorInfo *color;
    ssize_t offset;
} PESBlockInfo;

extern  PESColorInfo PESColor[256];
extern PESBlockInfo blocks[256];
extern ssize_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using a fixed index remapping (reverse order)
    for (ssize_t idx = 0; idx < 256L; idx++) {
        ssize_t rev_idx = 255 - idx;  // Reverse access pattern
        blocks[rev_idx].offset = 0;
        blocks[rev_idx].color = PESColor;
    }
    i = 256;  // Ensure loop invariant: i ends at 256
}
