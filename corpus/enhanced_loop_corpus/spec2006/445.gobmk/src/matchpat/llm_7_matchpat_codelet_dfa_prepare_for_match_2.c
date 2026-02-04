#include <stdio.h>

#include <inttypes.h>

typedef unsigned char Intersection;

extern int dfa_board_size;
extern int dfa_p[7056];
extern const int convert[3][4];
extern int color;
extern int i;
extern int j;
extern Intersection board[421];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Introduce loop-carried dependence via cumulative update (WAW and RAW)
    int accumulator = 0;
    for (i = 0; i < dfa_board_size; i++) {
        for (j = 0; j < dfa_board_size; j++) {
            int read_index = (19 + 2) + i * (19 + 1) + j;
            int write_index = (4 * 21 * i + j) + (4 * 21 * 21 + 21);
            // Artificially create a loop-carried RAW/WAW: current output depends on previous iteration
            if (i > 0 || j > 0)
                accumulator = dfa_p[write_index - 1]; // Read last written value
            dfa_p[write_index] = convert[color][board[read_index]] + accumulator;
        }
    }
}
