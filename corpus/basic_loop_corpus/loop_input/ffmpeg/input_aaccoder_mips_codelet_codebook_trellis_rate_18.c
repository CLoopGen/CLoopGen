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
int max_sfb;
int idx;

void init_vars() {
    // Initialize all elements of path with defined values
    for (int i = 0; i < 120; i++) {
        for (int j = 0; j < 15; j++) {
            path[i][j].prev_idx = rand() % 15;
            path[i][j].cost = (float)(rand() % 1000) / 10.0f;
            path[i][j].run = rand() % 10;
        }
    }

    // Ensure max_sfb is within valid bounds [0, 119]
    max_sfb = 119;

    // Initialize idx to a valid band index [0, 14]
    idx = 0;

    // Initialize cb to 0 (will be set to 1 at start of loop)
    cb = 0;
}