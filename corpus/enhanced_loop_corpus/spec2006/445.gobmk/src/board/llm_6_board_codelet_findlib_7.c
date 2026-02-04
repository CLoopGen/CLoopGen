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
    int temp_libs[4]; // Local buffer to reduce immediate write-back and alter data dependency
    int temp_count = 0;
    for (k = 0, pos = (string[s].origin); k < maxlib && k < liberties; pos = (next_stone[pos])) {
        temp_count = 0;
        // Collect up to 4 potential liberties without immediately updating shared `libs` or `ml`
        if ((board[((pos) + (19 + 1))] == 0 && ml[((pos) + (19 + 1))] != liberty_mark)) {
            temp_libs[temp_count++] = ((pos) + (19 + 1));
        }
        if ((board[((pos) - 1)] == 0 && ml[((pos) - 1)] != liberty_mark)) {
            temp_libs[temp_count++] = ((pos) - 1);
        }
        if ((board[((pos) - (19 + 1))] == 0 && ml[((pos) - (19 + 1))] != liberty_mark)) {
            temp_libs[temp_count++] = ((pos) - (19 + 1));
        }
        if ((board[((pos) + 1)] == 0 && ml[((pos) + 1)] != liberty_mark)) {
            temp_libs[temp_count++] = ((pos) + 1);
        }
        // Now commit the collected liberties to global state with controlled WAW/RAR dependencies
        for (int i = 0; i < temp_count && k < maxlib; ++i) {
            libs[k] = temp_libs[i];
            ml[temp_libs[i]] = liberty_mark;
            ++k;
        }
        if (k >= maxlib) break;
    }
}
