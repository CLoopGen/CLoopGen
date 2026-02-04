#include <stdio.h>
#include <inttypes.h>
#include <string.h>

int n;
int left_corner[19];
int right_corner[19];
int left_corners = 10;
int right_corners = 15;
int bottom_row = 5;
char mn[400];

void init_vars() {
    for (int i = 0; i < 19; i++) {
        left_corner[i] = (i + 1) * 37;  
        right_corner[i] = (i + 1) * 53; 
    }
    memset(mn, 0, sizeof(mn));
}