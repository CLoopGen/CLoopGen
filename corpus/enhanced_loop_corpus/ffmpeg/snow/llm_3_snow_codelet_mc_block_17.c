#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern int stride;
extern int b_w;
extern int b_h;
extern int dx;
extern int dy;
extern int x;
extern int y;
extern  uint8_t *src1;
extern  uint8_t *src2;
extern  uint8_t *src3;
extern  uint8_t *src4;
extern int stride1;
extern int stride2;
extern int stride3;
extern int stride4;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided Memory Access with Interleaved Computation
    // We modify the access pattern to process data in a strided manner across multiple rows at once,
    // simulating a blocked/tiled access pattern for improved cache reuse.
    // Here, we process two rows at a time if possible, accessing elements with larger strides
    // but within a localized block to exploit temporal locality.

    const int block_size = 2;
    int y = 0;

    for (; y <= b_h - block_size; y += block_size) {
        uint8_t *s1_row0 = src1 + y * stride1;
        uint8_t *s2_row0 = src2 + y * stride2;
        uint8_t *s3_row0 = src3 + y * stride3;
        uint8_t *s4_row0 = src4 + y * stride4;
        uint8_t *dst_row0 = dst + y * stride;

        uint8_t *s1_row1 = s1_row0 + stride1;
        uint8_t *s2_row1 = s2_row0 + stride2;
        uint8_t *s3_row1 = s3_row0 + stride3;
        uint8_t *s4_row1 = s4_row0 + stride4;
        uint8_t *dst_row1 = dst_row0 + stride;

        for (int x = 0; x < b_w; x++) {
            // Process current column for two consecutive rows
            dst_row0[x] = ((8 - dx) * (8 - dy) * s1_row0[x] + 
                           dx * (8 - dy) * s2_row0[x] + 
                           (8 - dx) * dy * s3_row0[x] + 
                           dx * dy * s4_row0[x] + 32) >> 6;

            dst_row1[x] = ((8 - dx) * (8 - dy) * s1_row1[x] + 
                           dx * (8 - dy) * s2_row1[x] + 
                           (8 - dx) * dy * s3_row1[x] + 
                           dx * dy * s4_row1[x] + 32) >> 6;
        }
    }

    // Handle remaining row(s) if b_h is not divisible by block_size
    for (; y < b_h; y++) {
        uint8_t *s1_cur = src1 + y * stride1;
        uint8_t *s2_cur = src2 + y * stride2;
        uint8_t *s3_cur = src3 + y * stride3;
        uint8_t *s4_cur = src4 + y * stride4;
        uint8_t *dst_cur = dst + y * stride;

        for (int x = 0; x < b_w; x++) {
            dst_cur[x] = ((8 - dx) * (8 - dy) * s1_cur[x] + 
                          dx * (8 - dy) * s2_cur[x] + 
                          (8 - dx) * dy * s3_cur[x] + 
                          dx * dy * s4_cur[x] + 32) >> 6;
        }
    }
}
