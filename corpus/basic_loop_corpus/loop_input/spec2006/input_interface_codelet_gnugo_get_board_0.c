#include <stdio.h>
#include <inttypes.h>

typedef unsigned char Intersection;

int board_size = 19;
Intersection board[421];
int b[19][19];
int i;
int j;

void init_vars() {
    // Initialize board with sample data (size 421, which is (19+2)*(19+1) + 19 to fit access pattern)
    for (int idx = 0; idx < 421; idx++) {
        board[idx] = (Intersection)(idx % 256);
    }
    
    // Ensure board_size stays within safe bounds for array accesses
    board_size = 19;
    
    // Initialize b array to zero
    for (int i0 = 0; i0 < 19; i0++) {
        for (int j0 = 0; j0 < 19; j0++) {
            b[i0][j0] = 0;
        }
    }
}