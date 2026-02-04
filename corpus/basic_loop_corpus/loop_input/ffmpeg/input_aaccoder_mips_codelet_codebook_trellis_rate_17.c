#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct TrellisBandCodingPath {
    int prev_idx;
    float cost;
    int run;
} TrellisBandCodingPath;

TrellisBandCodingPath path[120][15];
int cb;
int run_bits;

void init_vars() {
    run_bits = 8;
    for (int i = 0; i < 120; i++) {
        for (int j = 0; j < 15; j++) {
            path[i][j].prev_idx = 0;
            path[i][j].cost = 0.0f;
            path[i][j].run = 0;
        }
    }
}