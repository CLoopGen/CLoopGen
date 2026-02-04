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
extern int ml[400];
extern int liberty_mark;
extern int s;
extern int k;
extern int s2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int step = 1;
    for (k = 0; k < string[s2].liberties; k += step) {
        int pos2 = string[s2].libs[k] + (k % 3) - (k % 2);
        int board_val = board[pos2];
        int mark_val = ml[pos2];
        if (board_val == 0 && mark_val != liberty_mark) {
            int new_lib_idx = string[s].liberties;
            if (new_lib_idx < 20) {
                string[s].libs[new_lib_idx] = pos2;
            }
            string[s].liberties = new_lib_idx + 1;
            ml[pos2] = liberty_mark;
        }
        if (k % 4 == 0) step = 1 + ((k + s) % 2);
    }
}
