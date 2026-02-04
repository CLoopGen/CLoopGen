#include <stdio.h>

#include <inttypes.h>

extern int i;
extern int a;
extern int j;
extern int score;
extern int wdev_dscale;
extern int bdev_dscale;
extern int board[144];
extern int wking_loc;
extern int bking_loc;
extern int piece_count;
extern int pieces[62];
extern  int pcsqbishop[144];
extern  int black_knight[144];
extern  int white_knight[144];
extern  int white_pawn[144];
extern  int black_pawn[144];
extern  int black_queen[144];
extern  int white_queen[144];
extern  int black_rook[144];
extern  int white_rook[144];
extern unsigned char p_tropism[144][144];
extern unsigned char q_tropism[144][144];
extern unsigned char n_tropism[144][144];
extern unsigned char r_tropism[144][144];
extern unsigned char b_tropism[144][144];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_score = 0;
    for (a = 1, j = 1; a <= piece_count; j++) {
        i = pieces[j];
        if (!i)
            continue;
        else
            a++;
        switch (board[i]) {
          case (1):
            temp_score += 100;
            temp_score += white_pawn[i] >> wdev_dscale;
            temp_score += p_tropism[i][bking_loc];
            break;
          case (2):
            temp_score -= 100;
            temp_score -= black_pawn[i] >> bdev_dscale;
            temp_score -= p_tropism[i][wking_loc];
            break;
          case (7):
            temp_score += 250;
            temp_score += white_rook[i] >> wdev_dscale;
            temp_score += r_tropism[i][bking_loc];
            break;
          case (8):
            temp_score -= 250;
            temp_score -= black_rook[i] >> bdev_dscale;
            temp_score -= r_tropism[i][wking_loc];
            break;
          case (11):
            temp_score += 230;
            temp_score += pcsqbishop[i] >> wdev_dscale;
            temp_score += b_tropism[i][bking_loc];
            break;
          case (12):
            temp_score -= 230;
            temp_score -= pcsqbishop[i] >> bdev_dscale;
            temp_score -= b_tropism[i][wking_loc];
            break;
          case (3):
            temp_score += 210;
            temp_score += white_knight[i] >> wdev_dscale;
            temp_score += n_tropism[i][bking_loc];
            break;
          case (4):
            temp_score -= 210;
            temp_score -= black_knight[i] >> bdev_dscale;
            temp_score -= n_tropism[i][wking_loc];
            break;
          case (9):
            temp_score += 450;
            temp_score += white_queen[i] >> wdev_dscale;
            temp_score += q_tropism[i][bking_loc];
            break;
          case (10):
            temp_score -= 450;
            temp_score -= black_queen[i] >> bdev_dscale;
            temp_score -= q_tropism[i][wking_loc];
            break;
        }
    }
    score += temp_score;
}
