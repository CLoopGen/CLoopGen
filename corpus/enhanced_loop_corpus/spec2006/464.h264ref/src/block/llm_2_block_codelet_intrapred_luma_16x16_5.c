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

extern int s[16][2];
extern int i;
extern unsigned short **imgY_pred;
extern PixelPos up;
extern PixelPos left[17];
extern int up_avail;
extern int left_avail;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with local accumulation
    unsigned short temp_up[16];
    unsigned short temp_left[16];
    
    if (up_avail) {
        int base_y = up.pos_y;
        int base_x = up.pos_x;
        for (i = 0; i < 16; i++) {
            temp_up[i] = imgY_pred[base_y][base_x + i];
        }
    }
    
    if (left_avail) {
        for (i = 0; i < 16; i++) {
            int y = left[i + 1].pos_y;
            int x = left[i + 1].pos_x;
            temp_left[i] = imgY_pred[y][x];
        }
    }

    // Store accumulated results to s in a separate loop to decouple access from computation
    for (i = 0; i < 16; i++) {
        if (up_avail)
            s[i][0] = temp_up[i];
        if (left_avail)
            s[i][1] = temp_left[i];
    }
}
