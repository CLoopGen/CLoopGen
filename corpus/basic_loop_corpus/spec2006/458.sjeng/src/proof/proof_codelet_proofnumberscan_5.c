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
for (i = 0; i < num_moves; i++) {
    if (!rootlosers[i] && islegal[i]) {
        forcedwin = 1;
        pn_move = moves[i];
        break;
    }
}

}
