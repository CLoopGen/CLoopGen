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
    // Variant 1: Consecutive memory access by unrolling and accessing adjacent elements
    int start = ply + 1;
    int length = pv_length[ply + 1];
    int idx = start;

    for (j = start; j < length; j++, idx++) {
        pv[ply][idx] = pv[start][idx];
    }
}
