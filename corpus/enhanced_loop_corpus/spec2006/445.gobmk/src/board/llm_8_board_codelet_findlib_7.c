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
    // Variant 1: Increased computational intensity with unrolled and duplicated condition blocks
    // Trip count remains similar but each iteration performs more checks (simulated unrolling)
    // Additional arithmetic used in bounds checking and redundant safety conditions

    for (k = 0, pos = string[s].origin; k < maxlib && k < liberties && pos != 0; 
         pos = next_stone[pos]) {
        int offset;

        // First direction: +20 (down)
        offset = pos + 20;
        if (offset < 421 && board[offset] == 0 && ml[offset] != liberty_mark) {
            libs[k++] = offset;
            ml[offset] = liberty_mark;
            if (k >= maxlib) break;
        }

        // Second direction: -1 (left)
        offset = pos - 1;
        if (offset >= 0 && board[offset] == 0 && ml[offset] != liberty_mark) {
            libs[k++] = offset;
            ml[offset] = liberty_mark;
            if (k >= maxlib) break;
        }

        // Third direction: -20 (up)
        offset = pos - 20;
        if (offset >= 0 && board[offset] == 0 && ml[offset] != liberty_mark) {
            libs[k++] = offset;
            ml[offset] = liberty_mark;
            if (k >= maxlib) break;
        }

        // Fourth direction: +1 (right)
        offset = pos + 1;
        if (offset < 421 && board[offset] == 0 && ml[offset] != liberty_mark) {
            libs[k++] = offset;
            ml[offset] = liberty_mark;
            if (k >= maxlib) break;
        }

        // Extra computation: duplicate checks with adjusted arithmetic to increase intensity
        // Simulates partial loop unrolling with lookahead
        if (pos != next_stone[pos] && next_stone[pos] != 0) {
            int next_pos = next_stone[pos];
            int offsets[4] = {next_pos + 20, next_pos - 1, next_pos - 20, next_pos + 1};
            for (int j = 0; j < 4 && k < maxlib; j++) {
                int o = offsets[j];
                if (o >= 0 && o < 421 && board[o] == 0 && ml[o] != liberty_mark) {
                    libs[k++] = o;
                    ml[o] = liberty_mark;
                    if (k >= maxlib) break;
                }
            }
        }
    }
}
