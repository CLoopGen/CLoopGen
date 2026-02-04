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
    // Variant 1: Consecutive memory access by unrolling and accessing consecutive elements
    int start = ply + 1;
    int end = pv_length[ply + 1];
    for (int j = start; j < end; j += 2) {
        pv[ply][j] = pv[ply + 1][j];
        if (j + 1 < end) {
            pv[ply][j + 1] = pv[ply + 1][j + 1];
        }
    }
}
