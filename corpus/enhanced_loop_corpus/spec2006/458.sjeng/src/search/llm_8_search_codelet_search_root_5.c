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
    int start = ply + 1;
    int limit = pv_length[ply + 1];
    for (j = start; j < limit; j++) {
        pv[ply][j].from = pv[ply + 1][j].from;
        pv[ply][j].target = pv[ply + 1][j].target;
        pv[ply][j].captured = pv[ply + 1][j].captured;
        pv[ply][j].promoted = pv[ply + 1][j].promoted;
        pv[ply][j].castled = pv[ply + 1][j].castled;
        pv[ply][j].ep = pv[ply + 1][j].ep;
    }
}
