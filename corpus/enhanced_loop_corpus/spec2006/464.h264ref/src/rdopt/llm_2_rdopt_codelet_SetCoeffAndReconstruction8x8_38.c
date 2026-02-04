#include <stdio.h>

#include <inttypes.h>

extern int resTrans_R_8x8ts[16][16];
extern int resTrans_B_8x8ts[16][16];
extern int resTrans_R[16][16];
extern int resTrans_B[16][16];
extern int mprRGB[3][16][16];
extern int mprRGB_8x8ts[3][16][16];
extern int j;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access using pointer arithmetic to improve spatial locality
    int *mprRGB_ptr0 = &mprRGB[0][0][0];
    int *mprRGB_ptr1 = &mprRGB[1][0][0];
    int *mprRGB_ptr2 = &mprRGB[2][0][0];
    int *mprRGB_8x8ts_ptr0 = &mprRGB_8x8ts[0][0][0];
    int *mprRGB_8x8ts_ptr1 = &mprRGB_8x8ts[1][0][0];
    int *mprRGB_8x8ts_ptr2 = &mprRGB_8x8ts[2][0][0];
    int *resTrans_R_ptr = &resTrans_R[0][0];
    int *resTrans_B_ptr = &resTrans_B[0][0];
    int *resTrans_R_8x8ts_ptr = &resTrans_R_8x8ts[0][0];
    int *resTrans_B_8x8ts_ptr = &resTrans_B_8x8ts[0][0];

    for (j = 0; j < 16; j++) {
        for (i = 0; i < 16; i++) {
            int idx = j * 16 + i;
            *(mprRGB_ptr0 + idx) = *(mprRGB_8x8ts_ptr0 + idx);
            *(mprRGB_ptr1 + idx) = *(mprRGB_8x8ts_ptr1 + idx);
            *(mprRGB_ptr2 + idx) = *(mprRGB_8x8ts_ptr2 + idx);
            *(resTrans_R_ptr + idx) = *(resTrans_R_8x8ts_ptr + idx);
            *(resTrans_B_ptr + idx) = *(resTrans_B_8x8ts_ptr + idx);
        }
    }
}
