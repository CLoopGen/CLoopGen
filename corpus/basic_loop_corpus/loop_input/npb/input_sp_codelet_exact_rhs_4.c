#include <stdio.h>

int grid_points[3] = {64, 64, 64};
double forcing[5][65][65][65];
int m;
int i;
int j;
int k;

void init_vars() {
    grid_points[0] = 64;
    grid_points[1] = 64;
    grid_points[2] = 64;
}