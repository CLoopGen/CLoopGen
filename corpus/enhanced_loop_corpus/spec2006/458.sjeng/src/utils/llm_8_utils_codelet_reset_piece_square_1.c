#include <stdio.h>

#include <inttypes.h>

extern int i;
extern int promoted_board[144];
extern int board[144];
extern int squares[144];
extern int piece_count;
extern int pieces[62];
extern int is_promoted[62];
extern int Material;
extern int material[14];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int step = 2;
for (i = 26; i < 118; i += step)
    if (board[i] && (board[i] < 13)) {
        Material += material[board[i]];
        piece_count += 1;
        pieces[piece_count] = i;
        squares[i] = piece_count;
        if (promoted_board[i])
            is_promoted[piece_count] = 1;
    } else
        squares[i] = 0;

}
