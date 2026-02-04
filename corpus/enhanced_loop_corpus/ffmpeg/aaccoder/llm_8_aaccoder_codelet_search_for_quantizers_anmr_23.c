#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct TrellisPath {
    float cost;
    int prev;
} TrellisPath;

extern int i;
extern int idx;
extern TrellisPath paths[121][61];
extern int minq;
extern float mincost;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float temp_mincost = mincost;
    int temp_minq = minq;
    for (i = 1; i < (60 + 1); i += 2) {
        if (paths[idx][i].cost < temp_mincost) {
            temp_mincost = paths[idx][i].cost;
            temp_minq = i;
        }
        if (i + 1 <= 60 && paths[idx][i+1].cost < temp_mincost) {
            temp_mincost = paths[idx][i+1].cost;
            temp_minq = i + 1;
        }
    }
    mincost = temp_mincost;
    minq = temp_minq;
}
