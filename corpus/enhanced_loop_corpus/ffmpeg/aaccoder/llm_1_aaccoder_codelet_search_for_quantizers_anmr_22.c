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
    for (i = 0; i < (60 + 1); i += 2) {
        paths[0][i].cost = 0.F;
        paths[0][i].prev = -1;
        if (i + 1 <= 60) {
            paths[0][i + 1].cost = 0.F;
            paths[0][i + 1].prev = -1;
        }
    }
}
