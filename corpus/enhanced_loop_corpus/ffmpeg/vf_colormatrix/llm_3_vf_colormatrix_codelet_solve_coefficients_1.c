#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double cm[3][3];
extern double rgb[3][3];
extern double yuv[3][3];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Memory Access Pattern Modification using consecutive linear indexing (flattened access)
    double *cm_flat = &cm[0][0];
    double *rgb_flat = &rgb[0][0];
    double *yuv_flat = &yuv[0][0];
    int idx_cm, idx_rgb_col, idx_yuv_row;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            idx_cm = i * 3 + j;
            idx_yuv_row = i * 3;
            idx_rgb_col = j;
            cm_flat[idx_cm] = 
                yuv_flat[idx_yuv_row + 0] * rgb_flat[idx_rgb_col] +
                yuv_flat[idx_yuv_row + 1] * rgb_flat[3 + idx_rgb_col] +
                yuv_flat[idx_yuv_row + 2] * rgb_flat[6 + idx_rgb_col];
        }
    }
}
