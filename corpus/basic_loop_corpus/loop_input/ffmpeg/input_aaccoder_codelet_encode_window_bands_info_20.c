#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct BandCodingPath {
    int prev_idx;
    float cost;
    int run;
} BandCodingPath;

BandCodingPath path[120][15];
int cb;

void init_vars() {
    for (int i = 0; i < 120; i++) {
        for (int j = 0; j < 15; j++) {
            path[i][j].prev_idx = -1;
            path[i][j].cost = 0.0F;
            path[i][j].run = 0;
        }
    }
    cb = 0;
}