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

extern int forcedwin;
extern move_s pn_move;
extern int rootlosers[300];
extern move_s moves[512];
extern int islegal[512];
extern int i;
extern int num_moves;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int local_forcedwin = 0;
    move_s local_pn_move;
    for (i = 0; i < num_moves; i++) {
        if (!rootlosers[i] && islegal[i]) {
            local_pn_move = moves[i];
            local_forcedwin = 1;
            break;
        }
    }
    forcedwin = local_forcedwin;
    pn_move = local_pn_move;
}
