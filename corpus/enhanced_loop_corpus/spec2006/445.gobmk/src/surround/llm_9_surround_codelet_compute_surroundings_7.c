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
    // Variant 1: Increased computational intensity by unrolling the loop and adding redundant but safe arithmetic checks.
    // Trip count reduced by a factor of 2 via step increment of 2, but each iteration does more work.
    // Additional arithmetic operations introduced through offset pre-computation and duplicated condition framing.

    const int stride = 19 + 1;
    const int start = 19 + 2;
    const int end = stride * stride;

    for (dpos = start; dpos < end && surrounded; dpos += 2) {
        if ((board[dpos] != 3) && mf[dpos]) {
            int up = dpos - stride;
            int down = dpos + stride;
            int left = dpos - 1;
            int right = dpos + 1;

            // Precompute neighbor positions and flags
            int up_valid = (up >= stride);
            int down_valid = (down < end);
            int left_valid = ((dpos % stride) != 0);
            int right_valid = ((dpos % stride) != (stride - 1));

            if ((up_valid && (board[up] == 0) && (board[up] != 3) &&
                 (up - stride >= 0) && (board[up - stride] == color) && (board[up - stride] != 3) && mn[up - stride] != 1 &&
                 (right < end) && (board[right] != 3) && board[right] != other &&
                 (left >= 0) && (board[left] != 3) && board[left] != other) ||
                (down_valid && (board[down] == 0) && (board[down] != 3) &&
                 (down + stride < end) && (board[down + stride] == color) && (board[down + stride] != 3) && mn[down + stride] != 1 &&
                 (right < end) && (board[right] != 3) && board[right] != other &&
                 (left >= 0) && (board[left] != 3) && board[left] != other) ||
                (right_valid && (board[right] == 0) && (board[right] != 3) &&
                 (right + 1 < end) && ((right + 1) % stride != 0) && (board[right + 1] == color) && (board[right + 1] != 3) && mn[right + 1] != 1 &&
                 (up >= stride) && (board[up] != 3) && board[up] != other &&
                 (down < end) && (board[down] != 3) && board[down] != other) ||
                (left_valid && (board[left] == 0) && (board[left] != 3) &&
                 (left - 1 >= 0) && ((left - 1) % stride != (stride - 1)) && (board[left - 1] == color) && (board[left - 1] != 3) && mn[left - 1] != 1 &&
                 (up >= stride) && (board[up] != 3) && board[up] != other &&
                 (down < end) && (board[down] != 3) && board[down] != other)) {
                surrounded = 0;
            }
        }

        // Second unrolled iteration manually inlined to increase compute per loop
        int dpos2 = dpos + 1;
        if (dpos2 < end && (board[dpos2] != 3) && mf[dpos2]) {
            int up = dpos2 - stride;
            int down = dpos2 + stride;
            int left = dpos2 - 1;
            int right = dpos2 + 1;

            int up_valid = (up >= stride);
            int down_valid = (down < end);
            int left_valid = ((dpos2 % stride) != 0);
            int right_valid = ((dpos2 % stride) != (stride - 1));

            if ((up_valid && (board[up] == 0) && (board[up] != 3) &&
                 (up - stride >= 0) && (board[up - stride] == color) && (board[up - stride] != 3) && mn[up - stride] != 1 &&
                 (right < end) && (board[right] != 3) && board[right] != other &&
                 (left >= 0) && (board[left] != 3) && board[left] != other) ||
                (down_valid && (board[down] == 0) && (board[down] != 3) &&
                 (down + stride < end) && (board[down + stride] == color) && (board[down + stride] != 3) && mn[down + stride] != 1 &&
                 (right < end) && (board[right] != 3) && board[right] != other &&
                 (left >= 0) && (board[left] != 3) && board[left] != other) ||
                (right_valid && (board[right] == 0) && (board[right] != 3) &&
                 (right + 1 < end) && ((right + 1) % stride != 0) && (board[right + 1] == color) && (board[right + 1] != 3) && mn[right + 1] != 1 &&
                 (up >= stride) && (board[up] != 3) && board[up] != other &&
                 (down < end) && (board[down] != 3) && board[down] != other) ||
                (left_valid && (board[left] == 0) && (board[left] != 3) &&
                 (left - 1 >= 0) && ((left - 1) % stride != (stride - 1)) && (board[left - 1] == color) && (board[left - 1] != 3) && mn[left - 1] != 1 &&
                 (up >= stride) && (board[up] != 3) && board[up] != other &&
                 (down < end) && (board[down] != 3) && board[down] != other)) {
                surrounded = 0;
            }
        }
    }
}
