#include <stdio.h>
#include <inttypes.h>

int i;
int j;
int i1;
int j2;
int n2;
int n1;
int _usr_j1;
int mb_y;
int m5[4];
int predicted_chroma_block[8][8];

void init_vars() {
    for (int y = 0; y < 8; y++) {
        for (int x = 0; x < 8; x++) {
            predicted_chroma_block[y][x] = (x * 8 + y + 1) * 7;
        }
    }
    i = 0;
    j = 0;
    i1 = 0;
    j2 = 0;
    n2 = 0;
    n1 = 0;
    _usr_j1 = 0;
    mb_y = 0;
    for (int idx = 0; idx < 4; idx++) {
        m5[idx] = idx * 3;
    }
}