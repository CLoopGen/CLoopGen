#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int piece_count;
extern int pieces[62];
extern int xnum_pieces;
extern int j;
extern int a;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int local_a = 1;
    for (j = 1; local_a <= piece_count; j++) {
        i = pieces[j];
        if (!i) {
            continue;
        }
        int piece_type = board[i];
        if (piece_type != 1 && piece_type != 2 && piece_type != 13 && piece_type != 0) {
            xnum_pieces++;
        }
        local_a++;
    }
    a = local_a;
}
