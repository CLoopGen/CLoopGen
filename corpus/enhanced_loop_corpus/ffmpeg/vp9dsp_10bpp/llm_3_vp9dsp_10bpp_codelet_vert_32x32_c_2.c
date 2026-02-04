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
    // Variant 2: Strided access with transposed indexing — simulate column-major style writes
    // Instead of writing full rows per iteration, iterate over columns first,
    // and write each component (p4a..p4h) down its respective column across all rows.
    // This creates a strided access pattern where each store is separated by 'stride'.
    uint16_t *col_start[8];
    for (int i = 0; i < 8; i++) {
        col_start[i] = dst + i * 4; // Base pointer for each column (offset by 4 uint16s)
    }

    // Now write each of the 8 values down its own column, stepping by stride each time
    for (int y = 0; y < 32; y++) {
        ((av_alias64*)(col_start[0]))->u64 = p4a;
        ((av_alias64*)(col_start[1]))->u64 = p4b;
        ((av_alias64*)(col_start[2]))->u64 = p4c;
        ((av_alias64*)(col_start[3]))->u64 = p4d;
        ((av_alias64*)(col_start[4]))->u64 = p4e;
        ((av_alias64*)(col_start[5]))->u64 = p4f;
        ((av_alias64*)(col_start[6]))->u64 = p4g;
        ((av_alias64*)(col_start[7]))->u64 = p4h;

        // Step each column pointer by stride to next row
        for (int i = 0; i < 8; i++) {
            col_start[i] += stride;
        }
    }
}
