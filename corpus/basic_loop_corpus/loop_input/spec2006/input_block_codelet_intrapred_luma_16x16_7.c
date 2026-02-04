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

int i;
int ih;
int iv;
unsigned short **imgY_pred;
PixelPos up;
PixelPos left[17];

#define IMG_HEIGHT 2048
#define IMG_WIDTH 2048

void init_vars() {
    ih = 0;
    iv = 0;
    i = 0;

    imgY_pred = (unsigned short**)calloc(IMG_HEIGHT, sizeof(unsigned short*));
    for (int row = 0; row < IMG_HEIGHT; row++) {
        imgY_pred[row] = (unsigned short*)calloc(IMG_WIDTH, sizeof(unsigned short));
    }

    up.available = 1;
    up.mb_addr = 0;
    up.x = 0;
    up.y = 0;
    up.pos_x = 10;  
    up.pos_y = 100; 

    for (int idx = 0; idx < 17; idx++) {
        left[idx].available = 1;
        left[idx].mb_addr = idx;
        left[idx].x = idx;
        left[idx].y = idx;
        left[idx].pos_x = 20 + idx * 5;  
        left[idx].pos_y = 50 + idx * 3;  
    }
}