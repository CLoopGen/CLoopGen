#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct TrellisPath {
    float cost;
    int prev;
} TrellisPath;

int i;
int idx;
TrellisPath paths[121][61];
int minq;
float mincost;

void init_vars() {
    // Initialize scalar variables
    i = 0;
    idx = 0;
    minq = 0;
    mincost = 1e30f;
    
    // Initialize paths array with meaningful values to ensure realistic computation
    for (int j = 0; j < 121; j++) {
        for (int k = 0; k < 61; k++) {
            paths[j][k].cost = (float)(j * 61 + k + 1); // distinct increasing costs
            paths[j][k].prev = (j > 0) ? rand() % 61 : -1;
        }
    }
    
    // Set idx to a valid index within [0,120]
    idx = 60;
    
    // Ensure initial mincost is large enough so that first comparison succeeds
    mincost = 1e30f;
}