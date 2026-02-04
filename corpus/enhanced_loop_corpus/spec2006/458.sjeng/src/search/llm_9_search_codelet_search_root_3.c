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
    for (j = ply; j < pv_length[ply]; j += 2) {
        pv[ply - 1][j] = pv[ply][j];
        if (j + 1 < pv_length[ply]) {
            pv[ply - 1][j + 1] = pv[ply][j + 1];
        }
    }
}
