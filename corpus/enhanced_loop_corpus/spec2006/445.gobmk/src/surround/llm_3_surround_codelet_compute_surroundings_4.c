#include <stdio.h>

#include <inttypes.h>

extern int n;
extern int left_corner[19];
extern int right_corner[19];
extern int left_corners;
extern int right_corners;
extern int bottom_row;
extern char mn[400];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int start_idx = (left_corner[left_corners - 1]) % 20 - 1;
    int end_idx = (right_corner[right_corners - 1]) % 20 - 1;
    int stride = 1;
    int offset = (19 + 2) + (bottom_row) * (19 + 1);
    for (int k = 0; k <= (end_idx - start_idx); k += stride) {
        int n = start_idx + k;
        mn[offset + n] = 1;
    }
}
