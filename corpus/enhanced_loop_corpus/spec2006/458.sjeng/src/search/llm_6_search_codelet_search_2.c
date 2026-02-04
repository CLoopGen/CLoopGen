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
    int k;
    for (k = ply + 1; k < pv_length[ply + 1]; k++) {
        pv[ply][k] = pv[ply + 1][k];
        pv[ply][k].captured += pv[ply][k-1].captured; // Introduce WAW and RAW loop-carried dependency: each iteration depends on previous write
    }
}
