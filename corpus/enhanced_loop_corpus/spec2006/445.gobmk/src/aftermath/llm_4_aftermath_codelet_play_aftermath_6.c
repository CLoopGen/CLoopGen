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
for (pos = (19 + 2); pos < (19 + 1) * (19 + 1); pos++) {
    if (board[pos] == 3) {
        if (a->black_control[pos]) {
            a->black_area++;
            if (board[pos] == 1) {
                a->black_territory++;
                a->white_prisoners++;
                a->final_status[pos] = 0;
            } else if (board[pos] == 0) {
                a->black_territory++;
                a->final_status[pos] = 13;
            } else {
                a->final_status[pos] = 1;
            }
        } else if (a->white_control[pos]) {
            a->white_area++;
            if (board[pos] == 2) {
                a->white_territory++;
                a->black_prisoners++;
                a->final_status[pos] = 0;
            } else if (board[pos] == 0) {
                a->white_territory++;
                a->final_status[pos] = 14;
            } else {
                a->final_status[pos] = 1;
            }
        } else {
            if (board[pos] == 0) {
                a->final_status[pos] = 15;
            } else {
                a->final_status[pos] = 7;
                if (board[pos] == 1) {
                    a->white_area++;
                } else {
                    a->black_area++;
                }
            }
        }
    }
}
}
