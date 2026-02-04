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
    int base_index = (19 + 2) + (bottom_row) * (19 + 1);
    for (int i = 0, n = start; n <= end; n++, i++) {
        mn[base_index + n] = 1;
    }
}
