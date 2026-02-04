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
    for (int j = 0; j < 1; j++) {
        for (i = 0; i < (60 + 1); i++) {
            paths[0][i].cost = 0.F;
            paths[0][i].prev = -1;
        }
    }
}
