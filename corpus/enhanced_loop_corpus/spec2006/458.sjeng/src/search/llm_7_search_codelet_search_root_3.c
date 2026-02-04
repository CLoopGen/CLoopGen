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
    int temp_from[300], temp_target[300], temp_captured[300], temp_promoted[300], temp_castled[300], temp_ep[300];
    int i, count = 0;
    for (i = ply; i < pv_length[ply]; i++) {
        temp_from[count] = pv[ply][i].from;
        temp_target[count] = pv[ply][i].target;
        temp_captured[count] = pv[ply][i].captured;
        temp_promoted[count] = pv[ply][i].promoted;
        temp_castled[count] = pv[ply][i].castled;
        temp_ep[count] = pv[ply][i].ep;
        count++;
    }
    for (i = 0; i < count; i++) {
        pv[ply - 1][ply + i].from = temp_from[i];
        pv[ply - 1][ply + i].target = temp_target[i];
        pv[ply - 1][ply + i].captured = temp_captured[i];
        pv[ply - 1][ply + i].promoted = temp_promoted[i];
        pv[ply - 1][ply + i].castled = temp_castled[i];
        pv[ply - 1][ply + i].ep = temp_ep[i];
    }
}
