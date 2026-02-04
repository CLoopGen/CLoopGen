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
for (i = 1; i < 5; i++) {
    int offset_up_pos_x_plus = up.pos_x + 7 + i;
    int offset_up_pos_x_minus = up.pos_x + 7 - i;
    int diff_h = imgY_pred[up.pos_y][offset_up_pos_x_plus] - imgY_pred[up.pos_y][offset_up_pos_x_minus];
    ih += i * diff_h;

    int left_plus_y = left[8 + i].pos_y;
    int left_plus_x = left[8 + i].pos_x;
    int left_minus_y = left[8 - i].pos_y;
    int left_minus_x = left[8 - i].pos_x;
    int diff_v = imgY_pred[left_plus_y][left_plus_x] - imgY_pred[left_minus_y][left_minus_x];
    iv += i * diff_v;
}
}
