#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct TrellisPath {
    float cost;
    int prev;
} TrellisPath;

extern int i;
extern TrellisPath paths[121][61];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < (120 + 1); i += 2) {
        int j = i / 2;
        if (j <= 60) {
            paths[0][j].cost = 0.F;
            paths[0][j].prev = -1;
        }
    }
}
