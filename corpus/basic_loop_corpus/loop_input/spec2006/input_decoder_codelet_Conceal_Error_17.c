#include <stdint.h>

int i;
int j;
int resY[16][16];

void init_vars() {
    for (int ii = 0; ii < 16; ii++) {
        for (int jj = 0; jj < 16; jj++) {
            resY[jj][ii] = 0;
        }
    }
}