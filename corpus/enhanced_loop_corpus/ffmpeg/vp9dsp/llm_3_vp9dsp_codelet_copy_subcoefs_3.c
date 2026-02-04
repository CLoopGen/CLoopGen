#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef union __attribute__((may_alias)) {
    uint32_t u32;
    uint16_t u16[2];
    uint8_t u8[4];
    float f32;
} av_alias32;

extern int16_t *out;
extern int sz;
extern int bit_depth;
extern int n;
extern  int16_t *scan;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect access using pointer arithmetic and precomputed offsets
    int16_t *out_base = out;
    int offset_scale = (bit_depth == 8) ? 1 : 2;
    const int16_t *scan_ptr = &scan[n];
    int remaining = sz * sz - n;

    for (int i = 0; i < remaining; i++) {
        int rc = scan_ptr[i];
        int scaled_rc = rc * offset_scale;
        if (bit_depth == 8) {
            *(out_base + scaled_rc) = 0;
        } else {
            ((av_alias32*)(out_base + scaled_rc))->u32 = 0;
        }
    }
    n = sz * sz; // Ensure loop condition reflects completion
}
