#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef union __attribute__((may_alias)) {
    uint64_t u64;
    uint32_t u32[2];
    uint16_t u16[4];
    uint8_t u8[8];
    double f64;
    float f32[2];
} av_alias64;

extern ptrdiff_t stride;
extern uint16_t *dst;
extern uint64_t p4a;
extern uint64_t p4b;
extern uint64_t p4c;
extern uint64_t p4d;
extern uint64_t p4e;
extern uint64_t p4f;
extern uint64_t p4g;
extern uint64_t p4h;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by unrolling and writing to contiguous locations
    // Instead of strided row-wise writes, accumulate 8 rows' worth of data into a local buffer
    // and write them consecutively to minimize stride effects and improve spatial locality.
    uint16_t *base_dst = dst;
    av_alias64 row_data[8] = {0}; // Holds the 8x8 = 64-byte row pattern

    for (int y = 0; y < 32; y++) {
        row_data[0].u64 = p4a;
        row_data[1].u64 = p4b;
        row_data[2].u64 = p4c;
        row_data[3].u64 = p4d;
        row_data[4].u64 = p4e;
        row_data[5].u64 = p4f;
        row_data[6].u64 = p4g;
        row_data[7].u64 = p4h;

        // Write all 8 blocks (64 bytes) consecutively in memory
        for (int i = 0; i < 8; i++) {
            ((av_alias64*)(base_dst + i * 4))->u64 = row_data[i].u64;
        }
        base_dst += stride; // Move to next logical row
    }
    dst = base_dst - stride * 32; // Restore if needed (optional, depending on usage)
}
