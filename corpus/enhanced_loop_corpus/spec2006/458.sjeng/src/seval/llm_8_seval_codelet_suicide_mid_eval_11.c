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
for (j = 1, a = 1; (a <= piece_count) && (j < 62); j++) {
    i = pieces[j];
    if (!i)
        continue;
    else
        a++;
    ((void)(0));
    pawn_file = (Xfile[(i)]) + 1;
    srank = (Xrank[(i)]);
    if (board[i] == 1) {
        pawns[1][pawn_file]++;
        if (srank < white_back_pawn[pawn_file]) {
            white_back_pawn[pawn_file] = srank;
        }
        // Additional arithmetic to increase computational intensity
        int temp = srank * pawn_file;
        temp += temp >> 1;
        white_back_pawn[pawn_file] ^= (temp & 0x7);
    } else if (board[i] == 2) {
        pawns[0][pawn_file]++;
        if (srank > black_back_pawn[pawn_file]) {
            black_back_pawn[pawn_file] = srank;
        }
        // Additional arithmetic for symmetry
        int temp = srank + pawn_file * 2;
        temp -= temp >> 2;
        black_back_pawn[pawn_file] ^= (temp & 0x7);
    }
}
}
