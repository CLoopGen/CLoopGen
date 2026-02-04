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
    float local_min = __builtin_inff();
    int local_idx = -1;
    for (i = 1; i < (60 + 1); i += 2) {
        float cost1 = paths[idx][i].cost;
        if (cost1 < local_min) {
            local_min = cost1;
            local_idx = i;
        }
        if (i + 1 <= 60) {
            float cost2 = paths[idx][i + 1].cost;
            if (cost2 < local_min) {
                local_min = cost2;
                local_idx = i + 1;
            }
        }
    }
    if (local_idx != -1 && local_min < mincost) {
        mincost = local_min;
        minq = local_idx;
    }
}
