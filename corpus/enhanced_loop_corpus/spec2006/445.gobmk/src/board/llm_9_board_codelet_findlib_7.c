#include <stdio.h>

#include <inttypes.h>

typedef unsigned char Intersection;

struct string_data {
    int color;
    int size;
    int origin;
    int liberties;
    int libs[20];
    int neighbors;
    int neighborlist[160];
    int mark;
};


extern Intersection board[421];
extern struct string_data string[240];
extern int next_stone[400];
extern int ml[400];
extern int liberty_mark;
extern int maxlib;
extern int *libs;
extern int k;
extern int liberties;
extern int s;
extern int pos;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced computational complexity with simplified access pattern
    // Fewer conditional checks per iteration, reduced arithmetic via precomputed directions
    // Lower trip count expected due to early termination and aggressive pruning

    const int directions[4] = {20, -1, -20, 1};  // Precomputed offsets: down, left, up, right
    int num_dirs = 4;

    for (k = 0, pos = string[s].origin; 
         k < maxlib && k < liberties && pos != 0; 
         pos = next_stone[pos]) {

        // Process neighbors using loop over directions to reduce code duplication
        for (int d = 0; d < num_dirs && k < maxlib; d++) {
            int neighbor = pos + directions[d];
            
            // Combined bounds and logic check: assume board is padded so full range is valid
            // Remove redundant re-checks of k after every increment by relying on loop condition
            if (board[neighbor] == 0 && ml[neighbor] != liberty_mark) {
                libs[k] = neighbor;
                ml[neighbor] = liberty_mark;
                k++;  // Increment only once, let outer loop handle exit
            }
        }

        // Early exit if maximum number of collected liberties reached
        if (k >= maxlib) break;
    }
}
