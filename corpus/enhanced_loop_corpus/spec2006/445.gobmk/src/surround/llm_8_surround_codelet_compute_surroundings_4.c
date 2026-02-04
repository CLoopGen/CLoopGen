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
    int start = (left_corner[left_corners - 1]) % 20 - 1;
    int end = (right_corner[right_corners - 1]) % 20 - 1;
    int stride = 2;
    for (n = start; n <= end; n += stride) {
        mn[(21 + bottom_row * 20 + n)] = 1;
        if (n + 1 <= end) {
            mn[(21 + bottom_row * 20 + n + 1)] = 1;
        }
    }
}
