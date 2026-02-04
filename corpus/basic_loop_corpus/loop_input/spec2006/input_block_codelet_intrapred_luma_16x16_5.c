#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

typedef struct pix_pos {
    int available;
    int mb_addr;
    int x;
    int y;
    int pos_x;
    int pos_y;
} PixelPos;

int s[16][2];
int i;
unsigned short **imgY_pred;
PixelPos up;
PixelPos left[17];
int up_avail;
int left_avail;

void init_vars() {
    // Initialize up and left availability
    up_avail = 1;
    left_avail = 1;

    // Set up valid pixel positions to avoid out-of-bounds access
    up.pos_y = 0;
    up.pos_x = 0;

    for (int idx = 0; idx < 17; idx++) {
        left[idx].pos_y = idx;
        left[idx].pos_x = 0;
    }

    // Allocate imgY_pred as a 2D array with sufficient size
    // To ensure ~0.01 sec runtime, use moderate data size: 4096x4096 ≈ 32MB for unsigned short
    const int height = 4096;
    const int width = 4096;
    imgY_pred = (unsigned short**)malloc(height * sizeof(unsigned short*));
    for (int row = 0; row < height; row++) {
        imgY_pred[row] = (unsigned short*)malloc(width * sizeof(unsigned short));
        for (int col = 0; col < width; col++) {
            imgY_pred[row][col] = (unsigned short)((row + col) & 0xFFFF);
        }
    }
}