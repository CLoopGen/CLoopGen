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
    int temp_pawn_file, temp_srank;
    for (j = 1, a = 1; (a <= piece_count); j++) {
        i = pieces[j];
        if (!i)
            continue;
        else
            a++;
        ((void)(0));
        temp_pawn_file = (Xfile[(i)]) + 1;
        temp_srank = (Xrank[(i)]);
        if (board[i] == 1) {
            pawns[1][temp_pawn_file]++;
            if (temp_srank < white_back_pawn[temp_pawn_file]) {
                white_back_pawn[temp_pawn_file] = temp_srank;
            }
        } else if (board[i] == 2) {
            pawns[0][temp_pawn_file]++;
            if (temp_srank > black_back_pawn[temp_pawn_file]) {
                black_back_pawn[temp_pawn_file] = temp_srank;
            }
        }
    }
}
