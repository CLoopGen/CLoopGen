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
    // Variant 2: Strided memory access with a fixed stride (access every second element first, then fill gaps)
    // This creates a non-unit stride pattern: first even indices, then odd
    int n = 60 + 1;

    // First pass: access even indices
    for (i = 0; i < n; i += 2) {
        paths[0][i].cost = 0.F;
        paths[0][i].prev = -1;
    }

    // Second pass: access odd indices
    for (i = 1; i < n; i += 2) {
        paths[0][i].cost = 0.F;
        paths[0][i].prev = -1;
    }
}
