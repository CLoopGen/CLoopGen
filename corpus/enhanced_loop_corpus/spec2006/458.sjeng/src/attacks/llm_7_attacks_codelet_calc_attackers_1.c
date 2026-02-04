#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int square;
extern  int bishop_o[4];
extern int a_sq;
extern int i;
extern int attackers;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    int local_attackers = attackers;
    int j;
    for (i = 0, j = 3; i < 4; i++, j--) {
        int offset = bishop_o[i];
        a_sq = square + offset;
        int piece = board[a_sq];

        if (piece == 1 && (i % 2)) {
            local_attackers++;
        } else if (piece == 5) {
            local_attackers++;
        } else {
            int found = 0;
            for (int k = 0; k < 10 && !found; k++) {
                a_sq += offset;
                if (a_sq >= 144 || a_sq < 0) break;
                piece = board[a_sq];
                if (piece == 11 || piece == 9) {
                    local_attackers++;
                    found = 1;
                } else if (piece != 13) {
                    found = 1;
                }
            }
        }
    }
    attackers = local_attackers;
}
