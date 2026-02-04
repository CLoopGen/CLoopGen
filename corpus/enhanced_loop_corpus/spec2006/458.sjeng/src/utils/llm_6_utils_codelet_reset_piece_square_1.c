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
    int temp_material = 0;
    int temp_piece_count = 0;
    for (i = 26; i < 118; i++) {
        int local_index = 0;
        if (board[i] && (board[i] < 13)) {
            temp_material += material[board[i]];
            local_index = ++temp_piece_count;
            pieces[local_index] = i;
            squares[i] = local_index;
            if (promoted_board[i])
                is_promoted[local_index] = 1;
        } else {
            squares[i] = 0;
        }
    }
    Material += temp_material;
    piece_count += temp_piece_count;
}
