#include <stdio.h>

#include <inttypes.h>

typedef struct {
    int from;
    int target;
    int captured;
    int promoted;
    int castled;
    int ep;
} move_s;

extern int ply;
extern int pv_length[300];
extern move_s pv[300][300];
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Decreased depth: original single loop remains, but unrolled by a factor of 2 for performance hint
    int len = pv_length[ply + 1];
    for (j = ply + 1; j + 1 < len; j += 2) {
        pv[ply][j] = pv[ply + 1][j];
        pv[ply][j + 1] = pv[ply + 1][j + 1];
    }
    if (j < len)  // Handle remaining element if length is odd
        pv[ply][j] = pv[ply + 1][j];
}
