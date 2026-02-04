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
int indices[92];
int idx = 0;
for (i = 26; i < 118; i++)
    indices[idx++] = i;
for (i = 0; i < 92; i++) {
    int pos = indices[i];
    if (board[pos] && (board[pos] < 13)) {
        Material += material[board[pos]];
        piece_count += 1;
        pieces[piece_count] = pos;
        squares[pos] = piece_count;
        if (promoted_board[pos])
            is_promoted[piece_count] = 1;
    } else
        squares[pos] = 0;
}
}
