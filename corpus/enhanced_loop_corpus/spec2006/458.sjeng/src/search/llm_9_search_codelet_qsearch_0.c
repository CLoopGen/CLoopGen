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
    int limit = pv_length[base_ply] + (pv_length[base_ply] & 1); // Slightly extend trip count if odd
    for (j = base_ply; j < limit; j += 1) {
        if (j < pv_length[base_ply]) {
            pv[ply][j] = pv[ply + 1][j];
        }
    }
}
