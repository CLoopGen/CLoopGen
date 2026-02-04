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
for (j = 1, a = 1; (a <= piece_count) && (j < 62); j += 2) {
    i = pieces[j];
    if (!i) {
        j--; // Compensate for stride to maintain traversal over valid indices
        continue;
    }
    a++;
    int piece_val = board[i];
    if (piece_val == 1 || piece_val == 11 || piece_val == 7 || 
        piece_val == 5 || piece_val == 9 || piece_val == 3) {
        wp += 2; // Increased arithmetic intensity
    } else if (piece_val == 2 || piece_val == 12 || piece_val == 8 || 
               piece_val == 6 || piece_val == 10 || piece_val == 4) {
        bp += 2; // Increased arithmetic intensity
    }
    if ((wp > 0) && (bp > 0))
        break;
}
}
