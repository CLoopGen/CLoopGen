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
    for (j = 1, a = 1; a <= piece_count; j++) {
        i = pieces[j];
        if (!i) {
            continue;
        }
        a++;
        if (board[i] < 0 || board[i] > 13) {
            xnum_pieces++;
        } else if (board[i] != 1 && board[i] != 2 && board[i] != 13 && board[i] != 0) {
            xnum_pieces++;
        }
    }
}
