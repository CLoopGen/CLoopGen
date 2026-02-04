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
    // Variant 1: Strided Memory Access Pattern
    // Instead of sequential dpos++, we access memory with a fixed stride (e.g., every 2nd valid position)
    // We maintain loop bounds and condition, but step by a non-unit stride to create strided access.
    const int stride = 2;
    for (dpos = (19 + 2); dpos < (19 + 1) * (19 + 1) && surrounded; dpos += stride) {
        if ((board[dpos] != 3) && mf[dpos]) {
            int up = dpos - (19 + 1);
            int down = dpos + (19 + 1);
            int right = dpos + 1;
            int left = dpos - 1;

            int up_up = up - (19 + 1);
            int down_down = down + (19 + 1);
            int right_right = right + 1;
            int left_left = left - 1;

            if (((board[up] != 3) && board[up] == 0 && (board[up_up] != 3) && board[up_up] == color && mn[up_up] != 1 &&
                 (board[up + 1] != 3) && board[up + 1] != other && (board[up - 1] != 3) && board[up - 1] != other) ||
                ((board[down] != 3) && board[down] == 0 && (board[down_down] != 3) && board[down_down] == color && mn[down_down] != 1 &&
                 (board[down + 1] != 3) && board[down + 1] != other && (board[down - 1] != 3) && board[down - 1] != other) ||
                ((board[right] != 3) && board[right] == 0 && (board[right_right] != 3) && board[right_right] == color && mn[right_right] != 1 &&
                 (board[right - (19 + 1)] != 3) && board[right - (19 + 1)] != other && (board[right + (19 + 1)] != 3) && board[right + (19 + 1)] != other) ||
                ((board[left] != 3) && board[left] == 0 && (board[left_left] != 3) && board[left_left] == color && mn[left_left] != 1 &&
                 (board[left - (19 + 1)] != 3) && board[left - (19 + 1)] != other && (board[left + (19 + 1)] != 3) && board[left + (19 + 1)] != other)) {
                surrounded = 0;
            }
        }
    }
}
