#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
union __attribute__((packed)) __attribute__((may_alias)) unaligned_16 {
    uint16_t l;
};


extern uint8_t *dst_color;
extern  uint8_t *src;
extern int src_linesize;
extern int src_linestep;
extern int int_x;
extern int int_y;
extern int frac_x;
extern int frac_y;
extern int i;
extern int int_x1;
extern int int_y1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided Access with Transposed Step (Simulating Non-unit Stride)
    // Change access pattern to stride by 4 bytes (two pixels) each iteration, then handle alignment separately.
    // This simulates a vectorized-like access pattern with larger steps.

    int stride = 4; // Process two 16-bit values at once (32 bits), increasing stride
    int limit = src_linestep & ~3; // Round down to multiple of 4

    int ifx = (1 << 16) - frac_x;
    int ify = (1 << 16) - frac_y;

    for (int i = 0; i < limit; i += stride) {
        // Access two consecutive 16-bit samples in a strided manner
        int idx0 = src_linestep * int_x + i;
        int idx1 = src_linestep * int_x1 + i;
        int idy0 = src_linesize * int_y;
        int idy1 = src_linesize * int_y1;

        int s00 = ((const union unaligned_16*)&src[idx0 + idy0])->l;
        int s01 = ((const union unaligned_16*)&src[idx1 + idy0])->l;
        int s10 = ((const union unaligned_16*)&src[idx0 + idy1])->l;
        int s11 = ((const union unaligned_16*)&src[idx1 + idy1])->l;

        int s0 = ifx * s00 + frac_x * s01;
        int s1 = ifx * s10 + frac_x * s11;

        ((union unaligned_16*)&dst_color[i])->l = (uint16_t)(((int64_t)ify * s0 + (int64_t)frac_y * s1) >> 32);

        // Optional second pixel in the stride (i+2)
        if (i + 2 < src_linestep) {
            int s00_next = ((const union unaligned_16*)&src[idx0 + idy0 + 2])->l;
            int s01_next = ((const union unaligned_16*)&src[idx1 + idy0 + 2])->l;
            int s10_next = ((const union unaligned_16*)&src[idx0 + idy1 + 2])->l;
            int s11_next = ((const union unaligned_16*)&src[idx1 + idy1 + 2])->l;

            int s0_next = ifx * s00_next + frac_x * s01_next;
            int s1_next = ifx * s10_next + frac_x * s11_next;

            ((union unaligned_16*)&dst_color[i + 2])->l = (uint16_t)(((int64_t)ify * s0_next + (int64_t)frac_y * s1_next) >> 32);
        }
    }

    // Handle any remaining elements if src_linestep is not a multiple of 4
    for (int i = limit; i < src_linestep; i += 2) {
        int s00 = ((const union unaligned_16*)&src[src_linestep * int_x + i + src_linesize * int_y])->l;
        int s01 = ((const union unaligned_16*)&src[src_linestep * int_x1 + i + src_linesize * int_y])->l;
        int s10 = ((const union unaligned_16*)&src[src_linestep * int_x + i + src_linesize * int_y1])->l;
        int s11 = ((const union unaligned_16*)&src[src_linestep * int_x1 + i + src_linesize * int_y1])->l;

        int s0 = ifx * s00 + frac_x * s01;
        int s1 = ifx * s10 + frac_x * s11;

        ((union unaligned_16*)&dst_color[i])->l = (uint16_t)(((int64_t)ify * s0 + (int64_t)frac_y * s1) >> 32);
    }
}
