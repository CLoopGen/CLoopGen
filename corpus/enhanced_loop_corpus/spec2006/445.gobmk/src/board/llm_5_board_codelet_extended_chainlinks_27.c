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


extern int delta[8];
extern Intersection board[421];
extern struct string_data string[240];
extern int string_number[400];
extern int string_mark;
extern int str;
extern int adj[160];
extern int both_colors;
extern int n;
extern int k;
extern int r;
extern int libs[241];
extern int liberties;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (r = 0; r < liberties; r++) {
    int lib = libs[r];
    int board_str_val = board[str];
    for (k = 0; k < 4; k++) {
        int pos = lib + delta[k];
        int piece = board[pos];
        int expected_color = 1 + 2 - board_str_val;
        if (piece == expected_color || (both_colors && piece == board_str_val)) {
            int str_num = string_number[pos];
            if (string[str_num].mark == string_mark) continue;
            int origin = string[str_num].origin;
            adj[n] = origin;
            string[string_number[origin]].mark = string_mark;
            n++;
        }
    }
}
}
