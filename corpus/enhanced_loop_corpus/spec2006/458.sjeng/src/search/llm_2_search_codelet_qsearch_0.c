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
    int end = pv_length[ply + 1];
    for (int idx = 0; idx < end - start; idx++) {
        pv[ply][start + idx] = pv[ply + 1][start + idx];
    }
}
