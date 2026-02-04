#include <stdio.h>

int dims[3][3] = {
    {0, 0, 0},
    {0, 0, 0},
    {256, 256, 128}
};

int xstart[3] = {0, 0, 1};
int ystart[3] = {0, 0, 1};
int zstart[3] = {0, 0, 1};

int indexmap[128][256][256];

int i;
int j;
int k;
int ii;
int ii2;
int jj;
int ij2;
int kk;

void init_vars() {
    for (int k = 0; k < 128; k++) {
        for (int j = 0; j < 256; j++) {
            for (int i = 0; i < 256; i++) {
                indexmap[k][j][i] = 0;
            }
        }
    }
}