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
    int k = ply;
    for (j = k; j < pv_length[k]; j++) {
        move_s temp = pv[k][j];
        pv[k - 1][j] = temp;
    }
}
