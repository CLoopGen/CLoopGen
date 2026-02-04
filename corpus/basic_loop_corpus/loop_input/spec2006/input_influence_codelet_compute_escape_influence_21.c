#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char Intersection;

Intersection board[421];
char escape_value[400];
int ii;
char escape_values[400][2];
int cache_number = 0;

void init_vars() {
    const int data_size = 1 << 20;
    const int board_size = 421;
    const int escape_val_size = 400;

    for (int i = 0; i < board_size; ++i) {
        board[i] = (i >= 21 && i < 361) ? ((i % 7) + 1) : 3;
    }

    for (int i = 0; i < escape_val_size; ++i) {
        escape_value[i] = 0;
        escape_values[i][0] = (char)(i % 128);
        escape_values[i][1] = (char)((i + 50) % 128);
    }

    cache_number = 1;
    ii = 0;
}