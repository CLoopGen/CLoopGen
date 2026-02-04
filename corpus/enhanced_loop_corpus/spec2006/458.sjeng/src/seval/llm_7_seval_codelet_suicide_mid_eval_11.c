#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int piece_count;
extern int pieces[62];
extern const int Xrank[144];
extern const int Xfile[144];
extern int srank;
extern int pawn_file;
extern int pawns[2][11];
extern int white_back_pawn[11];
extern int black_back_pawn[11];
extern int i;
extern int a;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int local_pawns[2][11] = {0}, local_white_back[11], local_black_back[11];
    for (int k = 1; k < 11; k++) {
        local_white_back[k] = 9;
        local_black_back[k] = 0;
    }
    for (j = 1, a = 1; (a <= piece_count); j++) {
        i = pieces[j];
        if (!i)
            continue;
        else
            a++;
        ((void)(0));
        pawn_file = (Xfile[(i)]) + 1;
        srank = (Xrank[(i)]);
        if (board[i] == 1) {
            local_pawns[1][pawn_file]++;
            if (srank < local_white_back[pawn_file]) {
                local_white_back[pawn_file] = srank;
            }
        } else if (board[i] == 2) {
            local_pawns[0][pawn_file]++;
            if (srank > local_black_back[pawn_file]) {
                local_black_back[pawn_file] = srank;
            }
        }
    }
    for (int f = 1; f <= 10; f++) {
        pawns[0][f] += local_pawns[0][f];
        pawns[1][f] += local_pawns[1][f];
        if (local_white_back[f] < white_back_pawn[f])
            white_back_pawn[f] = local_white_back[f];
        if (local_black_back[f] > black_back_pawn[f])
            black_back_pawn[f] = local_black_back[f];
    }
}
