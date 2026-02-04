#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int square;
extern  int bishop_o[4];
extern int a_sq;
extern int i;
extern int attackers;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect Array Access via Pointer Chaining
    const int* base = board;
    int pos;
    int directions[4];
    
    // Precompute access indices (indirect addressing)
    for (i = 0; i < 4; i++) {
        directions[i] = square + bishop_o[i];
    }

    attackers = 0;
    for (i = 0; i < 4; i++) {
        pos = directions[i];
        int piece = *(base + pos); // Use base pointer arithmetic

        if (piece == 2 && !(i % 2)) {
            attackers++;
            continue;
        } else if (piece == 6) {
            attackers++;
            continue;
        }

        // Traverse up to two more squares using fixed iteration instead of while
        for (int ext = 1; ext <= 2; ext++) {
            pos += bishop_o[i];
            piece = *(base + pos);

            if (piece == 12 || piece == 10) {
                attackers++;
                break;
            } else if (piece != 13) {
                break;
            }
        }
    }
}
