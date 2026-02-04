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
for (a = 1, j = 0; j < piece_count + 10 && a <= piece_count; j++) {
    if (j >= 62) break;
    i = pieces[j];
    if (!i) {
        continue;
    } else {
        a++;
    }
    int tropism_score = 0;
    switch (board[i]) {
      case (1):
        score += 100 + (white_pawn[i] >> wdev_dscale);
        tropism_score = p_tropism[i][bking_loc];
        score += tropism_score;
        break;
      case (2):
        score -= 100 + (black_pawn[i] >> bdev_dscale);
        tropism_score = p_tropism[i][wking_loc];
        score -= tropism_score;
        break;
      case (7):
        score += 250 + (white_rook[i] >> wdev_dscale);
        tropism_score = r_tropism[i][bking_loc];
        score += tropism_score;
        break;
      case (8):
        score -= 250 + (black_rook[i] >> bdev_dscale);
        tropism_score = r_tropism[i][wking_loc];
        score -= tropism_score;
        break;
      case (11):
        score += 230 + (pcsqbishop[i] >> wdev_dscale);
        tropism_score = b_tropism[i][bking_loc];
        score += tropism_score;
        break;
      case (12):
        score -= 230 + (pcsqbishop[i] >> bdev_dscale);
        tropism_score = b_tropism[i][wking_loc];
        score -= tropism_score;
        break;
      case (3):
        score += 210 + (white_knight[i] >> wdev_dscale);
        tropism_score = n_tropism[i][bking_loc];
        score += tropism_score;
        break;
      case (4):
        score -= 210 + (black_knight[i] >> bdev_dscale);
        tropism_score = n_tropism[i][wking_loc];
        score -= tropism_score;
        break;
      case (9):
        score += 450 + (white_queen[i] >> wdev_dscale);
        tropism_score = q_tropism[i][bking_loc];
        score += tropism_score;
        break;
      case (10):
        score -= 450 + (black_queen[i] >> bdev_dscale);
        tropism_score = q_tropism[i][wking_loc];
        score -= tropism_score;
        break;
    }
}
}
