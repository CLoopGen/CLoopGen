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
    int j_start = ply + 1;
    int j_end = pv_length[ply + 1];
    for (int j = j_start; j < j_end; j++) {
        move_s temp = pv[ply + 1][j];
        temp.ep = temp.from ^ temp.target; // Eliminate direct loop-carried dependency by working on local copy and modifying independent fields
        pv[ply][j] = temp;
    }
}
