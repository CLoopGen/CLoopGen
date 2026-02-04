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
    int outer_n;
    for (outer_n = ((left_corner[left_corners - 1]) % (19 + 1) - 1); outer_n <= ((right_corner[right_corners - 1]) % (19 + 1) - 1); outer_n++) {
        n = outer_n;
        mn[((19 + 2) + (bottom_row) * (19 + 1) + (n))] = 1;
    }
}
