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
    int temp_black_area = a->black_area;
    int temp_white_area = a->white_area;
    int temp_black_territory = a->black_territory;
    int temp_white_territory = a->white_territory;
    int temp_black_prisoners = a->black_prisoners;
    int temp_white_prisoners = a->white_prisoners;

    for (pos = (19 + 2); pos < (19 + 1) * (19 + 1); pos++) {
        if (!(board[pos] != 3))
            continue;

        int local_final = 15;
        int update_black = 0, update_white = 0;
        int inc_black_area = 0, inc_white_area = 0;
        int inc_black_territory = 0, inc_white_territory = 0;
        int inc_black_prisoners = 0, inc_white_prisoners = 0;

        if (a->black_control[pos]) {
            update_black = 1;
            local_final = (board[pos] == 1) ? 0 : ((board[pos] == 0) ? 13 : 1);
            inc_black_area = 1;
            if (board[pos] == 1 || board[pos] == 0) {
                inc_black_territory = 1;
                if (board[pos] == 1) inc_white_prisoners = 1;
            }
        } else if (a->white_control[pos]) {
            update_white = 1;
            local_final = (board[pos] == 2) ? 0 : ((board[pos] == 0) ? 14 : 1);
            inc_white_area = 1;
            if (board[pos] == 2 || board[pos] == 0) {
                inc_white_territory = 1;
                if (board[pos] == 2) inc_black_prisoners = 1;
            }
        } else {
            local_final = (board[pos] == 0) ? 15 : 7;
            if (board[pos] != 0) {
                if (board[pos] == 1) inc_white_area = 1;
                else inc_black_area = 1;
            }
        }

        a->final_status[pos] = local_final;
        temp_black_area += inc_black_area;
        temp_white_area += inc_white_area;
        temp_black_territory += inc_black_territory;
        temp_white_territory += inc_white_territory;
        temp_black_prisoners += inc_black_prisoners;
        temp_white_prisoners += inc_white_prisoners;
    }

    a->black_area = temp_black_area;
    a->white_area = temp_white_area;
    a->black_territory = temp_black_territory;
    a->white_territory = temp_white_territory;
    a->black_prisoners = temp_black_prisoners;
    a->white_prisoners = temp_white_prisoners;
}
