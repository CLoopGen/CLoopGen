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
    // Variant 1: Consecutive Memory Access with Pointer Arithmetic
    Intersection *board_ptr = &board[19 + 2];
    int *black_ctrl = a->black_control + (19 + 2);
    int *white_ctrl = a->white_control + (19 + 2);
    int *final_stat = a->final_status + (19 + 2);
    int pos_idx = (19 + 2);
    
    for (int i = 0; i < (19 + 1) * (19 + 1) - (19 + 2); i++) {
        if (!((*board_ptr) != 3))
            continue;
        
        if (*(black_ctrl + i)) {
            a->black_area++;
            if (*(board_ptr + i) == 1) {
                a->black_territory++;
                a->white_prisoners++;
                *(final_stat + i) = 0;
            } else if (*(board_ptr + i) == 0) {
                a->black_territory++;
                *(final_stat + i) = 13;
            } else {
                *(final_stat + i) = 1;
            }
        } else if (*(white_ctrl + i)) {
            a->white_area++;
            if (*(board_ptr + i) == 2) {
                a->white_territory++;
                a->black_prisoners++;
                *(final_stat + i) = 0;
            } else if (*(board_ptr + i) == 0) {
                a->white_territory++;
                *(final_stat + i) = 14;
            } else {
                *(final_stat + i) = 1;
            }
        } else {
            if (*(board_ptr + i) == 0)
                *(final_stat + i) = 15;
            else {
                *(final_stat + i) = 7;
                if (*(board_ptr + i) == 1)
                    a->white_area++;
                else
                    a->black_area++;
            }
        }
        pos = pos_idx + i;
    }
}
