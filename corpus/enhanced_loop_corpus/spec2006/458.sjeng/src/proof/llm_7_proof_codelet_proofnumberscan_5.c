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
    int temp_i = 0;
    int found = 0;
    while (temp_i < num_moves && !found) {
        int idx = temp_i;
        if (!rootlosers[idx] && islegal[idx]) {
            forcedwin = 1;
            pn_move = moves[idx];
            found = 1;
        }
        temp_i++;
    }
    i = temp_i - 1;
}
