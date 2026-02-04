#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <time.h>

typedef float real_t;

__attribute__((aligned(64))) real_t aa[256][256];
int xindex;
int yindex;
real_t max;
real_t chksum;

void init_vars() {
    srand(time(NULL));
    for (int i = 0; i < 256; i++) {
        for (int j = 0; j < 256; j++) {
            aa[i][j] = (real_t)(rand() % 1000) / 10.0f;
        }
    }
    xindex = 0;
    yindex = 0;
    max = 0.0f;
    chksum = 0.0f;
}