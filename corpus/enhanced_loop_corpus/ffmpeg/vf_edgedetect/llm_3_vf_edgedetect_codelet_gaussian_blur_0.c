#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int w;
extern int h;
extern uint8_t *dst;
extern int dst_linesize;
extern  uint8_t *src;
extern int src_linesize;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 2; j < h - 2; j++) {
    dst[0] = src[0];
    if (w > 1)
        dst[1] = src[1];
    const int center_weight = 15, edge_weight = 12, corner_weight = 5;
    const int cross_near_weight = 9, cross_far_weight = 4, diag_near_weight = 4, diag_far_weight = 2;
    for (i = 2; i < w - 2; i++) {
        long sum = 0;
        // Access pattern: precompute base pointers to simulate strided access with offsets
        uint8_t *col_base_m2 = src - 2 * src_linesize;
        uint8_t *col_base_m1 = src - 1 * src_linesize;
        uint8_t *col_base_p1 = src + 1 * src_linesize;
        uint8_t *col_base_p2 = src + 2 * src_linesize;

        sum += (col_base_m2[i - 2] + col_base_p2[i - 2]) * diag_far_weight;
        sum += (col_base_m2[i - 1] + col_base_p2[i - 1]) * diag_near_weight;
        sum += (col_base_m2[i    ] + col_base_p2[i    ]) * diag_near_weight;
        sum += (col_base_m2[i + 1] + col_base_p2[i + 1]) * diag_near_weight;
        sum += (col_base_m2[i + 2] + col_base_p2[i + 2]) * diag_far_weight;

        sum += (col_base_m1[i - 2] + col_base_p1[i - 2]) * cross_far_weight;
        sum += (col_base_m1[i - 1] + col_base_p1[i - 1]) * cross_near_weight;
        sum += (col_base_m1[i    ] + col_base_p1[i    ]) * cross_near_weight;
        sum += (col_base_m1[i + 1] + col_base_p1[i + 1]) * cross_near_weight;
        sum += (col_base_m1[i + 2] + col_base_p1[i + 2]) * cross_far_weight;

        sum += src[i - 2] * corner_weight;
        sum += src[i - 1] * edge_weight;
        sum += src[i    ] * center_weight;
        sum += src[i + 1] * edge_weight;
        sum += src[i + 2] * corner_weight;

        dst[i] = (uint8_t)((sum + 79) / 159); // rounding division
    }
    if (w > 2)
        dst[i] = src[i];
    if (w > 3)
        dst[i + 1] = src[i + 1];
    dst += dst_linesize;
    src += src_linesize;
}
}
