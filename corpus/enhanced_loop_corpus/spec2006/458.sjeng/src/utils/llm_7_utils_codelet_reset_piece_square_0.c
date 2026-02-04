#include <stdio.h>

#include <inttypes.h>

extern int i;
extern int promoted_board[144];
extern int piece_count;
extern int pieces[62];
extern int is_promoted[62];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int prev_index = -1;
    for (i = 1; i <= piece_count; i++) {
        if (is_promoted[i]) {
            if (prev_index != -1) {
                promoted_board[pieces[prev_index]] += promoted_board[pieces[i]];
            }
            promoted_board[pieces[i]] = 1;
            prev_index = i;
        }
    }
}
