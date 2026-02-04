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
    // Variant 2: Strided memory access - simulate processing every 2nd element in interleaved fashion
    // This changes access pattern to strided and unrolls the logic partially for dual traversal
    
    int stride = 2;
    int limit = 16;

    // Handle even indices first (0, 2, 4, ..., 14), then odd (1, 3, 5, ..., 15)
    for (i = 0; i < limit; i += stride) {
        int j = i + 1; // next odd index

        if (up_avail) {
            s[i][0] = imgY_pred[up.pos_y][up.pos_x + i];  // even
            if (j < limit)
                s[j][0] = imgY_pred[up.pos_y][up.pos_x + j];
        }
        
        if (left_avail) {
            s[i][1] = imgY_pred[left[i + 1].pos_y][left[i + 1].pos_x];  // even
            if (j < limit)
                s[j][1] = imgY_pred[left[j + 1].pos_y][left[j + 1].pos_x];
        }
    }
}
