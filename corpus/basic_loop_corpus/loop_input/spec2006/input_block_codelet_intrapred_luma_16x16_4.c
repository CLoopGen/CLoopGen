#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

typedef struct pix_pos {
    int available;
    int mb_addr;
    int x;
    int y;
    int pos_x;
    int pos_y;
} PixelPos;

int s1 = 0;
int s2 = 0;
int i = 0;

#define IMG_HEIGHT 4096
#define IMG_WIDTH 4096

static unsigned short img_data[IMG_HEIGHT][IMG_WIDTH];
unsigned short **imgY_pred;

PixelPos up;
PixelPos left[17];

int up_avail = 1;
int left_avail = 1;

void init_vars() {
    // Allocate and initialize imgY_pred as a 2D array of size IMG_HEIGHT x IMG_WIDTH
    imgY_pred = (unsigned short**)malloc(IMG_HEIGHT * sizeof(unsigned short*));
    for (int row = 0; row < IMG_HEIGHT; row++) {
        imgY_pred[row] = img_data[row];
        for (int col = 0; col < IMG_WIDTH; col++) {
            img_data[row][col] = (unsigned short)(col + row + 1);
        }
    }

    // Initialize up position to a valid location near the middle of the image
    up.available = 1;
    up.mb_addr = 0;
    up.x = 100;
    up.y = 100;
    up.pos_y = 2048;  // within [0, IMG_HEIGHT)
    up.pos_x = 2000;  // such that pos_x + 15 < IMG_WIDTH

    // Initialize left array: ensure indices 1..16 are valid
    for (int idx = 0; idx < 17; idx++) {
        left[idx].available = 1;
        left[idx].mb_addr = idx;
        left[idx].x = 50 + idx;
        left[idx].y = 60 + idx;
        left[idx].pos_y = (2000 + idx) % IMG_HEIGHT;  // valid row
        left[idx].pos_x = 100;  // valid column, well within bounds
    }
}