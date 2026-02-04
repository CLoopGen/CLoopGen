#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int w = 65536;
int x;
int rnd = 0x12345678;

static int *alloc_scratch_row[2];
static int scratch_data[3][2][65536];

int *rnd_scratch[3][2] = {
    { scratch_data[0][0], scratch_data[0][1] },
    { scratch_data[1][0], scratch_data[1][1] },
    { scratch_data[2][0], scratch_data[2][1] }
};

void init_vars() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < w; k++) {
                scratch_data[i][j][k] = 0;
            }
        }
    }
    rnd = rand();
}