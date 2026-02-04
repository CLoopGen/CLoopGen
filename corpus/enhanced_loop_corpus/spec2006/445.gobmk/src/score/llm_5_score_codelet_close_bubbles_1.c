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
for (ii = (19 + 2); ii < (19 + 1) * (19 + 1); ii++) {
    // Flattened control: remove nested conditionals and restructure logic with early skips
    if (board[ii] != 3 && !gb[ii] && bubbles[ii] != 3) {

        // Immediate capture check due to enemy bubble adjacency
        if (((board[ii + 20] != 3) && bubbles[ii + 20] == 3) ||
            ((board[ii - 1]  != 3) && bubbles[ii - 1]  == 3) ||
            ((board[ii - 20] != 3) && bubbles[ii - 20] == 3) ||
            ((board[ii + 1]  != 3) && bubbles[ii + 1]  == 3)) {
            found_one = 1;
            bubbles[ii] = 3;
            continue;
        }

        int white_neighbor = 0, black_neighbor = 0;

        // Unify neighbor inspection with direct assignment via conditional expressions
        white_neighbor |= (bubbles[ii] == 1);
        white_neighbor |= (board[ii + 20] != 3 && (gb[ii + 20] > 0 || bubbles[ii + 20] == 1));
        white_neighbor |= (board[ii - 1]  != 3 && (gb[ii - 1]  > 0 || bubbles[ii - 1]  == 1));
        white_neighbor |= (board[ii - 20] != 3 && (gb[ii - 20] > 0 || bubbles[ii - 20] == 1));
        white_neighbor |= (board[ii + 1]  != 3 && (gb[ii + 1]  > 0 || bubbles[ii + 1]  == 1));

        black_neighbor |= (bubbles[ii] == 2);
        black_neighbor |= (board[ii + 20] != 3 && (gb[ii + 20] < 0 || bubbles[ii + 20] == 2));
        black_neighbor |= (board[ii - 1]  != 3 && (gb[ii - 1]  < 0 || bubbles[ii - 1]  == 2));
        black_neighbor |= (board[ii - 20] != 3 && (gb[ii - 20] < 0 || bubbles[ii - 20] == 2));
        black_neighbor |= (board[ii + 1]  != 3 && (gb[ii + 1]  < 0 || bubbles[ii + 1]  == 2));

        int new_color = 0;
        if (white_neighbor && black_neighbor) new_color = 3;
        else if (white_neighbor) new_color = 1;
        else if (black_neighbor) new_color = 2;

        if (new_color && new_color != bubbles[ii]) {
            found_one = 1;
            bubbles[ii] = new_color;
        }
    }
}
}
