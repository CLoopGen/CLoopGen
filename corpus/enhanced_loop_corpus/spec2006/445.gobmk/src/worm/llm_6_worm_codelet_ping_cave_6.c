#include <stdio.h>

#include <inttypes.h>

typedef unsigned char Intersection;

extern Intersection board[421];
extern int pos;
extern int mse[400];
extern int other;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int base = 19 + 1;
    int start = 19 + 2;
    int limit = base * base;
    for (pos = start; pos < limit; pos++) {
        int offset_up = pos + base;
        int offset_down = pos - base;
        int offset_left = pos - 1;
        int offset_right = pos + 1;
        Intersection current_board = board[pos];
        if ((current_board != 3) && mse[pos]) {
            Intersection up_val = board[offset_up];
            Intersection down_val = board[offset_down];
            Intersection left_val = board[offset_left];
            Intersection right_val = board[offset_right];
            int up_cond = (!(up_val != 3) || up_val == other);
            int down_cond = (!(down_val != 3) || down_val == other);
            int left_cond = (!(left_val != 3) || left_val == other);
            int right_cond = (!(right_val != 3) || right_val == other);
            if ((up_cond && down_cond) || (left_cond && right_cond))
                mse[pos] = 0;
        }
    }
}
