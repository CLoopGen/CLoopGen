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
    int local_ply = ply;
    if (local_ply >= 0) {
        for (j = local_ply; j < pv_length[local_ply]; j++)
            pv[local_ply - 1][j] = pv[local_ply][j];
    }
    // Reduced effective loop nesting by enclosing in a conditional block (no inner loops)
}
