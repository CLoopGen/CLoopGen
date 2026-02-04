#include <stdio.h>
#include <inttypes.h>

int i;
int j;
int M1[16][16];
int M0[4][4][4][4];

void init_vars() {
    for (int a = 0; a < 4; a++) {
        for (int b = 0; b < 4; b++) {
            for (int c = 0; c < 4; c++) {
                for (int d = 0; d < 4; d++) {
                    M0[a][b][c][d] = (a * 64 + b * 16 + c * 4 + d) % 17;
                }
            }
        }
    }
}