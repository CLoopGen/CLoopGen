#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

int mb_y = 10;
int mb_x = 10;
int i;
int block_x;
int block_y;

int mv[2][4][4];

short ***tmp_mv;

void init_vars() {
    // Allocate tmp_mv as [~68][~68][2] to allow indexing up to mb_x*4 + block_x + 4 and mb_y*4 + block_y
    // With mb_x = 10, block_x up to 3 -> max index: 10*4 + 3 + 4 = 47, similarly for y
    // Add padding to prevent out-of-bounds
    int size_x = 64;
    int size_y = 64;
    int size_z = 2;

    tmp_mv = (short***)calloc(size_x, sizeof(short**));
    for (int x = 0; x < size_x; x++) {
        tmp_mv[x] = (short**)calloc(size_y, sizeof(short*));
        for (int y = 0; y < size_y; y++) {
            tmp_mv[x][y] = (short*)calloc(size_z, sizeof(short));
            for (int z = 0; z < size_z; z++) {
                tmp_mv[x][y][z] = (x + y + z) % 100;
            }
        }
    }

    // Initialize mv to zero
    for (int a = 0; a < 2; a++)
        for (int b = 0; b < 4; b++)
            for (int c = 0; c < 4; c++)
                mv[a][b][c] = 0;
}