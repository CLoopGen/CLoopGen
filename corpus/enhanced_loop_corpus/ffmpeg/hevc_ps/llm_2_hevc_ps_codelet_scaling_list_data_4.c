#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct ScalingList {
    uint8_t sl[4][6][64];
    uint8_t sl_dc[2][6];
} ScalingList;

extern ScalingList *sl;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access using pointer arithmetic
    // Flatten the 3D array access into a linear traversal by computing offsets
    uint8_t *src_base = &sl->sl[2][1][0];
    uint8_t *dst_base = &sl->sl[3][1][0];
    for (i = 0; i < 64; i++) {
        dst_base[i + 0*64] = src_base[i + 0*64];  // sl[3][1][i] = sl[2][1][i]
        dst_base[i + 1*64] = src_base[i + 1*64];  // sl[3][2][i] = sl[2][2][i]
        dst_base[i + 3*64] = src_base[i + 3*64];  // sl[3][4][i] = sl[2][4][i]
        dst_base[i + 4*64] = src_base[i + 4*64];  // sl[3][5][i] = sl[2][5][i]
    }
}
