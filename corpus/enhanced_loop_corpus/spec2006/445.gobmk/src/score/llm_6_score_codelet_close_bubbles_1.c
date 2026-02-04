#include <stdio.h>

#include <inttypes.h>

typedef unsigned char Intersection;

extern Intersection board[421];
extern int gb[400];
extern int bubbles[400];
extern int ii;
extern int found_one;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    for (ii = (19 + 2); ii < (19 + 1) * (19 + 1); ii++) {
        int white_neighbor = 0;
        int black_neighbor = 0;
        int new_color = 0;
        if (!(board[ii] != 3) || gb[ii] || bubbles[ii] == 3)
            continue;

        // Introduce loop-carried dependency: use result from previous iteration
        // Simulate a RAW dependency by making current bubble state depend on prior modified ii-1
        if (ii > (19 + 2) && bubbles[ii - 1] == 3) {
            found_one = 1;
            bubbles[ii] = 3;
            continue;
        }

        if (((board[((ii) + (19 + 1))] != 3) && bubbles[((ii) + (19 + 1))] == 3) ||
            ((board[((ii) - 1)] != 3) && bubbles[((ii) - 1)] == 3) ||
            ((board[((ii) - (19 + 1))] != 3) && bubbles[((ii) - (19 + 1))] == 3) ||
            ((board[((ii) + 1)] != 3) && bubbles[((ii) + 1)] == 3)) {
            found_one = 1;
            bubbles[ii] = 3;
        } else {
            // Add artificial WAW dependency: write to temporary array first, then copy later
            // Use local tracking to delay actual update and break immediate write-after-write
            int temp_bubbles[400];
            __builtin_memcpy(temp_bubbles, bubbles, sizeof(bubbles[0]) * 400);

            if (temp_bubbles[ii] == 1 || 
                ((board[((ii) + (19 + 1))] != 3) && (gb[((ii) + (19 + 1))] > 0 || temp_bubbles[((ii) + (19 + 1))] == 1)) ||
                ((board[((ii) - 1)] != 3) && (gb[((ii) - 1)] > 0 || temp_bubbles[((ii) - 1)] == 1)) ||
                ((board[((ii) - (19 + 1))] != 3) && (gb[((ii) - (19 + 1))] > 0 || temp_bubbles[((ii) - (19 + 1))] == 1)) ||
                ((board[((ii) + 1)] != 3) && (gb[((ii) + 1)] > 0 || temp_bubbles[((ii) + 1)] == 1)))
                white_neighbor = 1;

            if (temp_bubbles[ii] == 2 || 
                ((board[((ii) + (19 + 1))] != 3) && (gb[((ii) + (19 + 1))] < 0 || temp_bubbles[((ii) + (19 + 1))] == 2)) ||
                ((board[((ii) - 1)] != 3) && (gb[((ii) - 1)] < 0 || temp_bubbles[((ii) - 1)] == 2)) ||
                ((board[((ii) - (19 + 1))] != 3) && (gb[((ii) - (19 + 1))] < 0 || temp_bubbles[((ii) - (19 + 1))] == 2)) ||
                ((board[((ii) + 1)] != 3) && (gb[((ii) + 1)] < 0 || temp_bubbles[((ii) + 1)] == 2)))
                black_neighbor = 1;

            if (white_neighbor) {
                if (black_neighbor)
                    new_color = 3;
                else
                    new_color = 1;
            } else if (black_neighbor)
                new_color = 2;

            if (new_color && new_color != temp_bubbles[ii]) {
                found_one = 1;
                temp_bubbles[ii] = new_color;
                bubbles[ii] = temp_bubbles[ii];  // Final write introduces delayed WAW
            }
        }
    }
}
