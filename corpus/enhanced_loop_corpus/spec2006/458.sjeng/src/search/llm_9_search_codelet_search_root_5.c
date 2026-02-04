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
    for (j = base_ply; j < len && j < pv_length[ply]; j += 2) {
        pv[ply][j] = pv[ply + 1][j];
        if (j + 1 < len && j + 1 < pv_length[ply]) {
            pv[ply][j + 1] = pv[ply + 1][j + 1];
        }
    }
}
