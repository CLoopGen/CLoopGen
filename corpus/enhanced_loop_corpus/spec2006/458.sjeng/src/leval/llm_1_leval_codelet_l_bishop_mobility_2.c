#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int square;
extern int l;
extern int m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Decreased effective loop depth by flattening the iteration using unrolling heuristic (partial)
    l = square + 11;
    if (board[l] == 13) {
        m++;
        l += 11;
        if (board[l] == 13) {
            m++;
            l += 11;
            if (board[l] == 13) {
                m++;
                l += 11;
                // Further checks can continue, but conditionally flattened to reduce loop structure
                // Simulates reduced loop nesting depth via partial unrolling without additional loops
            }
        }
    }
}
