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

int forcedwin;
move_s pn_move;
int rootlosers[300];
move_s moves[512];
int islegal[512];
int i;
int num_moves;

void init_vars() {
    forcedwin = 0;
    pn_move.from = 0;
    pn_move.target = 0;
    pn_move.captured = 0;
    pn_move.promoted = 0;
    pn_move.castled = 0;
    pn_move.ep = 0;

    for (int idx = 0; idx < 300; idx++) {
        rootlosers[idx] = 0;
    }

    for (int idx = 0; idx < 512; idx++) {
        moves[idx].from = idx;
        moves[idx].target = idx + 1;
        moves[idx].captured = 0;
        moves[idx].promoted = 0;
        moves[idx].castled = 0;
        moves[idx].ep = 0;
        islegal[idx] = (idx % 2);
    }

    num_moves = 512;
}