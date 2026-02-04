#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

const uint8_t ff_mpeg12_mbMotionVectorTable[17][2] = {
    {0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 5}, {5, 6}, {6, 7}, {7, 8},
    {8, 9}, {9,10}, {10,11}, {11,12}, {12,13}, {13,14}, {14,15}, {15,16},
    {16,17}
};

uint8_t mv_penalty[8][16385];
int f_code;
int mv;

void init_vars() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 16385; j++) {
            mv_penalty[i][j] = 0;
        }
    }
    f_code = 0;
    mv = 0;
}