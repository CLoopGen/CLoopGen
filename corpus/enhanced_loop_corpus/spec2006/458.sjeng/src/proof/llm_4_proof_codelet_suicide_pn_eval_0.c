#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int piece_count;
extern int pieces[62];
extern int j;
extern int a;
extern int i;
extern int wp;
extern int bp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 1 , a = 1; (a <= piece_count); j++) {
    i = pieces[j];
    if (!i)
        continue;
    a++;
    if (board[i] >= 1 && board[i] <= 12) {
        if (board[i] == 1 || board[i] == 11 || board[i] == 7 || board[i] == 5 || board[i] == 9 || board[i] == 3) {
            wp++;
        } else if (board[i] == 2 || board[i] == 12 || board[i] == 8 || board[i] == 6 || board[i] == 10 || board[i] == 4) {
            bp++;
        }
    }
    if (wp && bp)
        break;
}
}
