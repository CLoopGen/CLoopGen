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
    // Variant 2: Strided memory access with stride of 2, processing every second element first, then the offset
    int start = ply + 1;
    int end = pv_length[ply + 1];
    // First pass: even indices (relative to start)
    for (int j = start; j < end; j += 2) {
        pv[ply][j] = pv[ply + 1][j];
    }
    // Second pass: odd indices (relative to start)
    for (int j = start + 1; j < end; j += 2) {
        pv[ply][j] = pv[ply + 1][j];
    }
}
