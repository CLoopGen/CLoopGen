#include <stdio.h>

#include <inttypes.h>

extern int n;
extern int left_corner[19];
extern int right_corner[19];
extern int top_row;
extern char mn[400];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int start = (left_corner[0] % 19);
    int end = (right_corner[0] % 19);
    for (n = start; n <= end; n += 2) {
        mn[(20 + top_row * 20 + n)] = 1;
        if (n + 1 <= end) {
            mn[(20 + top_row * 20 + n + 1)] = 1;
        }
    }
}
