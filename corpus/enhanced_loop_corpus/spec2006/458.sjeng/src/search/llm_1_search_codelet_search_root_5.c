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
    int outer;
    int inner;
    for (outer = 0; outer < 1; outer++) {
        for (inner = ply + 1; inner < pv_length[ply + 1]; inner++) {
            pv[ply][inner] = pv[ply + 1][inner];
            j = inner;
        }
    }
}
