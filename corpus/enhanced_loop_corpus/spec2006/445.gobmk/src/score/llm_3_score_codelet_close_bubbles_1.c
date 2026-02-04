#include <stdio.h>

#include <inttypes.h>

typedef unsigned char Intersection;

extern Intersection board[421];
extern int gb[400];
extern int bubbles[400];
extern int ii;
extern int found_one;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect Memory Access via Index Array
    // Use an auxiliary index array to access board, gb, and bubbles indirectly.
    // This simulates irregular or gather-style memory access patterns.

    int indices[400];
    int num_indices = 0;
    int start = (19 + 2);
    int end = (19 + 1) * (19 + 1);

    // Precompute valid indices within bounds
    for (int temp_ii = start; temp_ii < end; temp_ii++) {
        indices[num_indices++] = temp_ii;
    }

    // Traverse using indirect access through index array
    for (int idx = 0; idx < num_indices; idx++) {
        ii = indices[idx];  // Map logical index via indirection
        int white_neighbor = 0;
        int black_neighbor = 0;
        int new_color = 0;

        if (!(board[ii] != 3) || gb[ii] || bubbles[ii] == 3)
            continue;

        int offset_up = ii + (19 + 1);
        int offset_left = ii - 1;
        int offset_down = ii - (19 + 1);
        int offset_right = ii + 1;

        if (((board[offset_up] != 3) && bubbles[offset_up] == 3) ||
            ((board[offset_left] != 3) && bubbles[offset_left] == 3) ||
            ((board[offset_down] != 3) && bubbles[offset_down] == 3) ||
            ((board[offset_right] != 3) && bubbles[offset_right] == 3)) {
            found_one = 1;
            bubbles[ii] = 3;
        } else {
            if (bubbles[ii] == 1 || 
                ((board[offset_up] != 3) && (gb[offset_up] > 0 || bubbles[offset_up] == 1)) ||
                ((board[offset_left] != 3) && (gb[offset_left] > 0 || bubbles[offset_left] == 1)) ||
                ((board[offset_down] != 3) && (gb[offset_down] > 0 || bubbles[offset_down] == 1)) ||
                ((board[offset_right] != 3) && (gb[offset_right] > 0 || bubbles[offset_right] == 1)))
                white_neighbor = 1;

            if (bubbles[ii] == 2 || 
                ((board[offset_up] != 3) && (gb[offset_up] < 0 || bubbles[offset_up] == 2)) ||
                ((board[offset_left] != 3) && (gb[offset_left] < 0 || bubbles[offset_left] == 2)) ||
                ((board[offset_down] != 3) && (gb[offset_down] < 0 || bubbles[offset_down] == 2)) ||
                ((board[offset_right] != 3) && (gb[offset_right] < 0 || bubbles[offset_right] == 2)))
                black_neighbor = 1;

            if (white_neighbor) {
                if (black_neighbor)
                    new_color = 3;
                else
                    new_color = 1;
            } else if (black_neighbor)
                new_color = 2;

            if (new_color && new_color != bubbles[ii]) {
                found_one = 1;
                bubbles[ii] = new_color;
            }
        }
    }
}
