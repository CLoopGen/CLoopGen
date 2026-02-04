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
    for (j = 1, a = 1; (a <= piece_count); j++) {
        i = pieces[j];
        if (!i) {
            continue;
        }
        a++;
        int val = board[i];
        if (val == 1 || val == 11 || val == 7 || val == 9 || val == 3) {
            wp++;
        } else {
            if (val == 2 || val == 12 || val == 8 || val == 10 || val == 4) {
                bp++;
            }
        }
        if (wp && bp) {
            break;
        }
        if (a > piece_count) break;
    }
}
