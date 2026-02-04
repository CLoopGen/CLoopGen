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

extern int s1;
extern int s2;
extern int i;
extern unsigned short **imgY_pred;
extern PixelPos up;
extern PixelPos left[17];
extern int up_avail;
extern int left_avail;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 16; i++) {
        if (!up_avail && !left_avail) 
            continue;
        if (up_avail)
            s1 += imgY_pred[up.pos_y][up.pos_x + i];
        if (left_avail)
            s2 += imgY_pred[left[i + 1].pos_y][left[i + 1].pos_x];
    }
}
