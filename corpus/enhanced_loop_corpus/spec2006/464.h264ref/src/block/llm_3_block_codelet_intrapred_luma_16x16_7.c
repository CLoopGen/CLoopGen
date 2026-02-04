#include <stdio.h>

#include <inttypes.h>

typedef struct pix_pos {
    int available;
    int mb_addr;
    int x;
    int y;
    int pos_x;
    int pos_y;
} PixelPos;

extern int i;
extern int ih;
extern int iv;
extern unsigned short **imgY_pred;
extern PixelPos up;
extern PixelPos left[17];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int offsets_h[8], offsets_v[16];
for (int j = 1; j < 9; j++) {
    offsets_h[j-1] = j;
    offsets_v[8 + j] = j;
    offsets_v[8 - j] = -j;
}
for (i = 1; i < 9; i++) {
    int h_val = imgY_pred[up.pos_y][up.pos_x + 7 + offsets_h[i-1]] - (i < 8 ? imgY_pred[up.pos_y][up.pos_x + 7 - offsets_h[i-1]] : imgY_pred[left[0].pos_y][left[0].pos_x]);
    ih += i * h_val;
    int vy1 = left[8 + i].pos_y, vx1 = left[8 + i].pos_x;
    int vy2 = left[8 - i].pos_y, vx2 = left[8 - i].pos_x;
    iv += i * (imgY_pred[vy1][vx1] - imgY_pred[vy2][vx2]);
}
}
