#include <stdio.h>

#include <inttypes.h>

extern int n;
extern int left_corner[19];
extern int right_corner[19];
extern int top_row;
extern char mn[400];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int base_index = (19 + 2) + (top_row) * (19 + 1);
    int trip_count = (right_corner[0] % 20) - (left_corner[0] % 20) + 1;
    for (n = 0; n < trip_count && n < 38; n++) {
        mn[base_index + (left_corner[0] % 19) + n] = 1;
    }
}
