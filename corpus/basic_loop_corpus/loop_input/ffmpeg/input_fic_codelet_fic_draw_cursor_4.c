#include <stdint.h>
#include <stdlib.h>

uint8_t planes[4][1024];
uint8_t chroma[3][256];
int i;
int j;
int p;

void init_vars() {
    for (int idx = 0; idx < 4; idx++) {
        for (int jdx = 0; jdx < 1024; jdx++) {
            planes[idx][jdx] = rand() % 256;
        }
    }
    for (int idx = 0; idx < 3; idx++) {
        for (int jdx = 0; jdx < 256; jdx++) {
            chroma[idx][jdx] = 0;
        }
    }
    i = 0;
    j = 0;
    p = 0;
}