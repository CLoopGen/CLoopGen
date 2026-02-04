#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

short ref = 0;
int list = 0;
int blocktype = 0;
short mv_x = 10;
short mv_y = -5;
int i;
int j;
int block_x = 0;
int block_y = 0;
int bsx = 128;
int bsy = 128;

short ******all_mv;

void init_vars() {
    int size_x = (bsx >> 2);
    int size_y = (bsy >> 2);
    int max_block_x = block_x + size_x;
    int max_block_y = block_y + size_y;

    all_mv = (short ******)calloc(max_block_x, sizeof(short *****));
    for (int i = 0; i < max_block_x; i++) {
        all_mv[i] = (short *****)calloc(max_block_y, sizeof(short ****));
        for (int j = 0; j < max_block_y; j++) {
            all_mv[i][j] = (short ****)calloc(2, sizeof(short ***)); 
            for (int l = 0; l < 2; l++) {
                all_mv[i][j][l] = (short ***)calloc(2, sizeof(short **));
                for (int r = 0; r < 2; r++) {
                    all_mv[i][j][l][r] = (short **)calloc(2, sizeof(short *));
                    for (int bt = 0; bt < 2; bt++) {
                        all_mv[i][j][l][r][bt] = (short *)calloc(2, sizeof(short));
                    }
                }
            }
        }
    }
}