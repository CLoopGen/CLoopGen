#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int mode = 12;
int x;
uint16_t *left;
int inv_angle[32];
uint16_t *ref_tmp;
int last = -1048576; // ensures about 1MB of data processed

void init_vars() {
    // Allocate and initialize inv_angle
    for (int i = 0; i < 32; i++) {
        inv_angle[i] = 256; // reasonable scale factor so shift by 8 yields original magnitude
    }

    // Adjust mode to be within valid index range: mode-11 must be valid index
    mode = 12; // so mode-11 = 1, which is valid

    // Allocate left array: we need to access left[-1 + ((x * inv_angle[mode-11] + 128) >> 8)]
    // When x = last = -1048576, index becomes: -1 + ((-1048576 * 256 + 128) >> 8)
    // = -1 + ((-268435456 + 128) >> 8) = -1 + (-268435328 >> 8) = -1 - 1048576 = -1048577
    // So we need left to cover at least from offset -1048577 to some positive margin
    // We will use a base pointer with sufficient headroom via offset allocation

    size_t total_size = 2097152; // ~4MB for uint16_t (2 bytes each), allows indexing from -1048577 to +1048575
    uint16_t *raw_left = (uint16_t*)calloc(total_size, sizeof(uint16_t));
    if (!raw_left) exit(1);

    // Set left pointer such that index -1048577 is accessible at raw_left[0]
    left = &raw_left[1048577]; // now left[-1048577] == raw_left[0]

    // Similarly for ref_tmp: written from x = last to -1 => indices -1048576 to -1
    uint16_t *raw_ref = (uint16_t*)calloc(1048576, sizeof(uint16_t));
    if (!raw_ref) exit(1);

    // We want ref_tmp[x] for x in [-1048576, -1] to be valid
    // So set ref_tmp so that ref_tmp[-1048576] maps to raw_ref[0]
    ref_tmp = &raw_ref[1048576]; // now ref_tmp[-1048576] = raw_ref[0], ..., ref_tmp[-1] = raw_ref[1048575]

    // Ensure all memory is initialized and ready
}