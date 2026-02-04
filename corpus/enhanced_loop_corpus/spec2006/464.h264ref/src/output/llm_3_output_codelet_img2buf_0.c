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



void loop() {
    // Variant 2: Consecutive (flattened index) memory access with linearized outer loop
    int total_elements = (size_y - crop_bottom - crop_top) * (size_x - crop_right - crop_left);
    int idx = 0;
    for (int linear_idx = 0; linear_idx < total_elements; linear_idx++) {
        i = crop_top + linear_idx / (size_x - crop_right - crop_left);
        j = crop_left + linear_idx % (size_x - crop_right - crop_left);
        ui8 = (unsigned char)(imgX[i][j]);
        buf[idx++] = ui8;
    }
}
