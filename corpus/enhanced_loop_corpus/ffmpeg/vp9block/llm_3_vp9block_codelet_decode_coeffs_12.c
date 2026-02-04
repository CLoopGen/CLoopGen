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

extern int end_y;
extern int n;
extern uint8_t *l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with increased stride (every 4th byte instead of every 2nd)
    // This changes access pattern to non-consecutive, strided locations, skipping more elements.
    // Each write is still 8-byte aligned via av_alias64, but step is larger.
    uint64_t factor = 72340172838076673ULL;
    for (n = 0; n < end_y; n += 4) {  // Increased stride to 4
        if (n + 7 < end_y) {  // Ensure 8-byte write doesn't overflow
            ((av_alias64 *)(&l[n]))->u64 = (l[n] * factor);
        }
    }
}
