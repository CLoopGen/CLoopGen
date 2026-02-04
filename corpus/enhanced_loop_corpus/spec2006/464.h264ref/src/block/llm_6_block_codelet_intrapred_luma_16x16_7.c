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
    int temp_ih = 0;
    int temp_iv = 0;
    for (i = 1; i < 9; i++) {
        int idx_up = up.pos_x + 7 + i;
        int idx_up_prev = up.pos_x + 7 - i;
        int left_y_high = left[8 + i].pos_y;
        int left_x_high = left[8 + i].pos_x;
        int left_y_low = left[8 - i].pos_y;
        int left_x_low = left[8 - i].pos_x;

        if (i < 8) {
            temp_ih += i * (imgY_pred[up.pos_y][idx_up] - imgY_pred[up.pos_y][idx_up_prev]);
        } else {
            temp_ih += i * (imgY_pred[up.pos_y][idx_up] - imgY_pred[left[0].pos_y][left[0].pos_x]);
        }
        temp_iv += i * (imgY_pred[left_y_high][left_x_high] - imgY_pred[left_y_low][left_x_low]);
    }
    ih += temp_ih;
    iv += temp_iv;
}
