#include <stdio.h>

#include <inttypes.h>

extern int i;
extern int promoted_board[144];
extern int piece_count;
extern int pieces[62];
extern int is_promoted[62];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i <= piece_count; i++) {
        int p = pieces[i];
        if (is_promoted[i] && p >= 0) {
            promoted_board[p] = 1;
        }
    }
}
