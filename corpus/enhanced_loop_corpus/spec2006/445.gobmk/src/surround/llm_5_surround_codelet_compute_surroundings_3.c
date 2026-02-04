#include <stdio.h>

#include <inttypes.h>

extern int n;
extern int left_corner[19];
extern int right_corner[19];
extern int top_row;
extern char mn[400];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (n = ((left_corner[0]) % (19 + 1) - 1); n <= ((right_corner[0]) % (19 + 1) - 1); n++) {
        if (n == (left_corner[0] % 19)) continue;
        mn[((19 + 2) + (top_row) * (19 + 1) + (n))] = 1;
    }
}
