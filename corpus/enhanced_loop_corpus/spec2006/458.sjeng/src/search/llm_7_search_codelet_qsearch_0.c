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
    int temp_length = pv_length[ply + 1];
    int offset = ply + 1;
    for (j = offset; j < temp_length; j++) {
        move_s temp = pv[offset][j];
        pv[ply][j] = temp;
    }
}
