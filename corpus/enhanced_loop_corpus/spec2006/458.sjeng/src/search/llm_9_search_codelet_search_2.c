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
    int base_ply = ply + 1;
    int len = pv_length[base_ply];
    for (j = base_ply; j < len; j++) {
        move_s temp = pv[ply + 1][j];
        pv[ply][j].from = temp.from;
        pv[ply][j].target = temp.target;
        pv[ply][j].captured = temp.captured;
        pv[ply][j].promoted = temp.promoted;
        pv[ply][j].castled = temp.castled;
        pv[ply][j].ep = temp.ep;
    }
}
