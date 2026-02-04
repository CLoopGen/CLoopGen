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
int j;
for (i = 1; i < 13; i++) {
    if (i < 8) {
        int term1 = imgY_pred[up.pos_y][up.pos_x + 7 + i];
        int term2 = imgY_pred[up.pos_y][up.pos_x + 7 - i];
        ih += i * (term1 - term2);
    } else if (i == 8) {
        ih += i * (imgY_pred[up.pos_y][up.pos_x + 15] - imgY_pred[up.pos_y][up.pos_x - 1]);
    } else if (i == 9) {
        ih += i * (imgY_pred[up.pos_y][up.pos_x + 16] - imgY_pred[up.pos_y][up.pos_x - 2]);
    } else {
        ih += (i - 8) * (imgY_pred[left[i - 1].pos_y][left[i - 1].pos_x] - imgY_pred[left[17 - i].pos_y][left[17 - i].pos_x]);
    }
    for (j = 0; j < 2; j++) {
        int idx = 8 + ((j == 0) ? i : (i-1));
        if (idx <= 16) {
            iv += i * (imgY_pred[left[idx].pos_y][left[idx].pos_x] - imgY_pred[left[16 - idx].pos_y][left[16 - idx].pos_x]);
        }
    }
}
}
