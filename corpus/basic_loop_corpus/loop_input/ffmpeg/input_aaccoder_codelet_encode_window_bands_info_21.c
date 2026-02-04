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
int max_sfb = 119;  
int idx = 0;

void init_vars() {
    for (int i = 0; i < 120; i++) {
        for (int j = 0; j < 15; j++) {
            path[i][j].prev_idx = rand() % 100;
            path[i][j].cost = (float)(rand() % 1000) / 10.0f;
            path[i][j].run = rand() % 20;
        }
    }
    cb = 0;
    idx = 0;
}