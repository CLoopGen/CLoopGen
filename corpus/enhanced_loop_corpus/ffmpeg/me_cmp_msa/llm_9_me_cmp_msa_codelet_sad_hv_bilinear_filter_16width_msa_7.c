#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern int32_t src_stride;
extern uint8_t *ref;
extern int32_t ref_stride;
extern int32_t height;
extern int32_t ht_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Reduced trip count with simplified operations and unrolled structure
ht_cnt = height >> 4;
if (ht_cnt <= 0) return;

for (; ht_cnt--; ) {
    // Merge multiple stride updates into fewer steps
    src += (8 * src_stride);
    ref += (8 * ref_stride);

    // Minimal computation: only essential memory access with simple arithmetic
    uint8_t val_src = src[-4 * src_stride];
    uint8_t val_ref = ref[-3 * ref_stride];

    // Single combined operation per iteration
    uint8_t result = (val_src ^ val_ref) + 1;
    
    src[-7 * src_stride] = result;
    ref[-7 * ref_stride] = result ^ 0xFF;

    // Additional lightweight operations without loops
    result = (result * 3) >> 2;
    src[-6 * src_stride] = result;
    ref[-6 * ref_stride] = result;
}
}
