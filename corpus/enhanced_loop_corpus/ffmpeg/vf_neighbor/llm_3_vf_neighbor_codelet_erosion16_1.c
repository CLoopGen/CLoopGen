#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef union __attribute__((may_alias)) {
    uint16_t u16;
    uint8_t u8[2];
} av_alias16;

extern  uint8_t *p1;
extern int width;
extern int threshold;
extern  uint8_t *coordinates[];
extern int coord;
extern uint16_t *dst;
extern int x;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect Memory Access Pattern via Index Array
    // Use an index array to enable indirect, non-sequential access to coordinate pointers,
    // simulating a gather-style operation. This increases irregularity in memory access.

    // Build active list of coordinate indices based on 'coord' bitmask
    int active_indices[8];
    int active_count = 0;
    for (i = 0; i < 8; i++) {
        if (coord & (1 << i)) {
            active_indices[active_count++] = i;
        }
    }

    for (x = 0; x < width; x++) {
        // Base value from p1 at offset 2*x
        int min = ((const av_alias16 *)(&p1[2 * x]))->u16;
        int limit = (min - threshold > 0) ? min - threshold : 0;

        // Traverse only active coordinates using indirect indexing
        for (i = 0; i < active_count; i++) {
            int idx = active_indices[i]; // Indirect access to coordinate index
            uint16_t val = ((const av_alias16 *)(coordinates[idx] + x * 2))->u16;
            min = (val < min) ? val : min;
        }
        min = (min < limit) ? limit : min;
        dst[x] = min;
    }
}
