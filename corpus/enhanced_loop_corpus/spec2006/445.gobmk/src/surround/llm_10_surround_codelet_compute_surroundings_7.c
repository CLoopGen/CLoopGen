#include <stdio.h>

#include <inttypes.h>

typedef unsigned char Intersection;

extern Intersection board[421];
extern int dpos;
extern int surrounded;
extern int color;
extern int other;
extern char mf[400];
extern char mn[400];

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Reduced computational intensity with early exits and simplified condition evaluation.
    // Loop runs over a smaller effective range by skipping edge-adjacent positions where neighbors would be out-of-bounds.
    // Arithmetic operations minimized by using constants and removing redundant parentheses.

    const int N = 19;
    const int stride = N + 1;
    const int board_size = stride * stride;
    const int margin = stride;

    // Skip outermost ring where neighbor checks would go out of bounds
    for (dpos = stride + 1; dpos < board_size - stride && surrounded; dpos++) {
        if (board[dpos] == 3 || !mf[dpos]) continue;

        int adj, adj2, side1, side2;

        // Check upward direction
        adj = dpos - stride;
        if (board[adj] == 0 && board[adj] != 3) {
            adj2 = adj - stride;
            if (board[adj2] == color && board[adj2] != 3 && mn[adj2] != 1) {
                side1 = adj + 1;
                side2 = adj - 1;
                if (board[side1] != 3 && board[side1] != other &&
                    board[side2] != 3 && board[side2] != other) {
                    surrounded = 0;
                    continue;
                }
            }
        }

        // Check downward direction
        adj = dpos + stride;
        if (board[adj] == 0 && board[adj] != 3) {
            adj2 = adj + stride;
            if (board[adj2] == color && board[adj2] != 3 && mn[adj2] != 1) {
                side1 = adj + 1;
                side2 = adj - 1;
                if (board[side1] != 3 && board[side1] != other &&
                    board[side2] != 3 && board[side2] != other) {
                    surrounded = 0;
                    continue;
                }
            }
        }

        // Check right direction
        adj = dpos + 1;
        if (board[adj] == 0 && board[adj] != 3) {
            adj2 = adj + 1;
            if (board[adj2] == color && board[adj2] != 3 && mn[adj2] != 1) {
                side1 = adj - stride;
                side2 = adj + stride;
                if (board[side1] != 3 && board[side1] != other &&
                    board[side2] != 3 && board[side2] != other) {
                    surrounded = 0;
                    continue;
                }
            }
        }

        // Check left direction
        adj = dpos - 1;
        if (board[adj] == 0 && board[adj] != 3) {
            adj2 = adj - 1;
            if (board[adj2] == color && board[adj2] != 3 && mn[adj2] != 1) {
                side1 = adj - stride;
                side2 = adj + stride;
                if (board[side1] != 3 && board[side1] != other &&
                    board[side2] != 3 && board[side2] != other) {
                    surrounded = 0;
                    continue;
                }
            }
        }
    }
}
