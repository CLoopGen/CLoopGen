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
    int* length_ptr = &pv_length[ply + 1];
    int current_ply = ply;
    int next_ply = ply + 1;
    for (j = next_ply; j < *length_ptr; j += 1) {
        pv[current_ply][j] = pv[next_ply][j];
    }
}
