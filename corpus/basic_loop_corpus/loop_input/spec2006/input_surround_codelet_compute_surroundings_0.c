#include <stdio.h>
#include <inttypes.h>
#include <string.h>
#include <stdlib.h>

int board_size = 19;
int m;
int n;
int top_row = -1;
int left_corner[19];
char mn[400];

void init_vars() {
    board_size = 19;

    top_row = -1;
    memset(left_corner, 0, sizeof(left_corner));

    memset(mn, 0, sizeof(mn));

    int target_index = (19 + 2) + (5) * (19 + 1) + (5);
    if (target_index < 400) {
        mn[target_index] = 1;
    }

    m = 0;
    n = 0;
}