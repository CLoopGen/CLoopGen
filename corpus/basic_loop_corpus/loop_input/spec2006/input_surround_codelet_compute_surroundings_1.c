#include <stdio.h>
#include <inttypes.h>

int board_size = 20;
int m;
int n;
int bottom_row;

char mn[400];

void init_vars() {
    board_size = 20;
    m = 0;
    n = 0;
    bottom_row = -1;

    for (int i = 0; i < 400; i++) {
        mn[i] = 0;
    }

    int target_index = (19 + 2) + (board_size - 1) * (19 + 1) + 0;
    if (target_index < 400 && target_index >= 0) {
        mn[target_index] = 1;
    }
}