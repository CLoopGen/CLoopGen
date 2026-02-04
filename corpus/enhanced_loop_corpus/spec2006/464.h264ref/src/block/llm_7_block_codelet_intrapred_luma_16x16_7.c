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
    int local_h[8] = {0};
    int local_v[8] = {0};
    for (i = 1; i < 9; i++) {
        if (i < 8) {
            local_h[i-1] = i * (imgY_pred[up.pos_y][up.pos_x + 7 + i] - imgY_pred[up.pos_y][up.pos_x + 7 - i]);
        } else {
            local_h[i-1] = i * (imgY_pred[up.pos_y][up.pos_x + 7 + i] - imgY_pred[left[0].pos_y][left[0].pos_x]);
        }
        local_v[i-1] = i * (imgY_pred[left[8 + i].pos_y][left[8 + i].pos_x] - imgY_pred[left[8 - i].pos_y][left[8 - i].pos_x]);
    }
    for (i = 0; i < 8; i++) {
        ih += local_h[i];
        iv += local_v[i];
    }
}
