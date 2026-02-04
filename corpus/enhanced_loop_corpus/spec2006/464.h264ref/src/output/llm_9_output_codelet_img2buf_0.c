#include <stdio.h>

#include <inttypes.h>

extern unsigned short **imgX;
extern unsigned char *buf;
extern int size_x;
extern int size_y;
extern int crop_left;
extern int crop_right;
extern int crop_top;
extern int crop_bottom;
extern int i;
extern int j;
extern int twidth;
extern unsigned char ui8;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int start_i = crop_top;
    int end_i = size_y - crop_bottom;
    int start_j = crop_left;
    int end_j = size_x - crop_right;
    int adjusted_twidth = (end_j - start_j);
    int total_elements = (end_i - start_i) * adjusted_twidth;
    for (int linear_idx = 0; linear_idx < total_elements; linear_idx++) {
        int flat_i = linear_idx / adjusted_twidth;
        int flat_j = linear_idx % adjusted_twidth;
        int src_i = start_i + flat_i;
        int src_j = start_j + flat_j;
        buf[linear_idx] = (unsigned char)(imgX[src_i][src_j]);
    }
}
