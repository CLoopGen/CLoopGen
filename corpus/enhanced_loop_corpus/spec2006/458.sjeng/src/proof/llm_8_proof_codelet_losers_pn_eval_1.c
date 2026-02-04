#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int piece_count;
extern int pieces[62];
extern int i;
extern int j;
extern int a;
extern int wp;
extern int bp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 1, a = 1; (a <= piece_count) && (j < 62); j++) {
        i = pieces[j];
        if (!i) {
            continue;
        } else {
            a++;
        }
        int tile = board[i];
        if (tile == 1 || tile == 11 || tile == 7 || tile == 9 || tile == 3) {
            wp++;
        } else if (tile == 2 || tile == 12 || tile == 8 || tile == 10 || tile == 4) {
            bp++;
        }
        if (wp > 0 && bp > 0) {
            break;
        }
    }
}
