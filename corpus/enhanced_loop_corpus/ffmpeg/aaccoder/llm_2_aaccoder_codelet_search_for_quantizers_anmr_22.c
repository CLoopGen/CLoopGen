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
    // Variant 1: Consecutive memory access using pointer arithmetic for improved spatial locality
    TrellisPath* ptr = &paths[0][0];
    for (i = 0; i < (60 + 1); i++) {
        ptr->cost = 0.F;
        ptr->prev = -1;
        ptr++;
    }
}
