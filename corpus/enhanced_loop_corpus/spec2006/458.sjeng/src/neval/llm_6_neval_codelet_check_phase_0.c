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
    int temp_xnum = 0;
    for (j = 1, a = 1; a <= piece_count; j++) {
        i = pieces[j];
        if (!i)
            continue;
        else
            a++;
        int val = board[i];
        if (val != 1 && val != 2 && val != 13 && val != 0) {
            temp_xnum++;
        }
    }
    xnum_pieces += temp_xnum;
}
