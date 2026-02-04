#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int w = 1024;
int type = 0;
int s = 0;
int i = 0;
int j = 0;
int dec_count = 3;
int tmp[1024 * 1024];
int level = 0;
int ori = 0;
int scale[2][2][4][4];

void init_vars() {
    w = 1024;
    type = 0;
    s = 0;
    dec_count = 3;
    for (int i = 0; i < 1024 * 1024; i++) {
        tmp[i] = rand() % 100 - 50;
    }
    for (int a = 0; a < 2; a++)
        for (int b = 0; b < 2; b++)
            for (int c = 0; c < 4; c++)
                for (int d = 0; d < 4; d++)
                    scale[a][b][c][d] = rand() % 10 + 1;
}