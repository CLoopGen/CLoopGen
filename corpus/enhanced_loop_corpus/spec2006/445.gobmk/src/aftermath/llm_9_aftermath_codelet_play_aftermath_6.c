#include <stdio.h>

#include <inttypes.h>

typedef unsigned char Intersection;

struct aftermath_data {
    int white_captured;
    int black_captured;
    int white_prisoners;
    int black_prisoners;
    int white_territory;
    int black_territory;
    int white_area;
    int black_area;
    int white_control[400];
    int black_control[400];
    int final_status[400];
};


extern Intersection board[421];
extern int pos;
extern struct aftermath_data *a;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int start = 19 + 2;
int end = (19 + 1) * (19 + 1);
int step = 1;
for (pos = start; pos < end; pos += step) {
    int board_val = board[pos];
    if (board_val == 3) continue;

    int* control_black = &(a->black_control[pos]);
    int* control_white = &(a->white_control[pos]);

    if (*control_black) {
        a->black_area++;
        if (board_val == 1) {
            a->black_territory += 1;
            a->white_prisoners += 1;
            a->final_status[pos] = 0;
        } else if (board_val == 0) {
            a->black_territory += 1;
            a->final_status[pos] = 13;
        } else {
            a->final_status[pos] = 1;
        }
    } else if (*control_white) {
        a->white_area++;
        if (board_val == 2) {
            a->white_territory += 1;
            a->black_prisoners += 1;
            a->final_status[pos] = 0;
        } else if (board_val == 0) {
            a->white_territory += 1;
            a->final_status[pos] = 14;
        } else {
            a->final_status[pos] = 1;
        }
    } else {
        if (board_val == 0) {
            a->final_status[pos] = 15;
        } else {
            a->final_status[pos] = 7;
            if (board_val == 1) {
                a->white_area += 1;
            } else {
                a->black_area += 1;
            }
        }
    }
}
}
