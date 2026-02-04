#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct TrellisPath {
    float cost;
    int prev;
} TrellisPath;

int i;
TrellisPath paths[121][61];

void init_vars() {
    for (int j = 0; j < 121; j++) {
        for (int k = 0; k < 61; k++) {
            paths[j][k].cost = 0.0f;
            paths[j][k].prev = -1;
        }
    }
}