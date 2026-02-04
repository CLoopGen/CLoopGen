#include <stdio.h>
#include <inttypes.h>

int i;
int promoted_board[144];
int piece_count = 60;
int pieces[62];
int is_promoted[62];

void init_vars() {
    for (int idx = 0; idx < 62; idx++) {
        pieces[idx] = idx % 144;
        is_promoted[idx] = (idx % 7) == 0;
    }
    for (int idx = 0; idx < 144; idx++) {
        promoted_board[idx] = 0;
    }
    i = 0;
}