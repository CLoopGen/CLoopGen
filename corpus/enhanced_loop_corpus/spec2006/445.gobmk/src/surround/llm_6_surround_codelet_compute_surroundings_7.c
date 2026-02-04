#include <stdio.h>

#include <inttypes.h>

typedef unsigned char Intersection;

extern Intersection board[421];
extern int dpos;
extern int surrounded;
extern int color;
extern int other;
extern char mf[400];
extern char mn[400];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (dpos = (19 + 2); dpos < (19 + 1) * (19 + 1) && surrounded; dpos++) {
        if ((board[dpos] != 3) && mf[dpos]) {
            int up_ok = (board[(dpos - (19 + 1))] != 3) && (board[(dpos - (19 + 1))] == 0);
            int up_chain = (board[(dpos - 2*(19 + 1))] != 3) && (board[(dpos - 2*(19 + 1))] == color) && (mn[(dpos - 2*(19 + 1))] != 1);
            int up_sides = (board[(dpos - (19 + 1) + 1)] != 3) && (board[(dpos - (19 + 1) + 1)] != other) &&
                           (board[(dpos - (19 + 1) - 1)] != 3) && (board[(dpos - (19 + 1) - 1)] != other);

            int down_ok = (board[(dpos + (19 + 1))] != 3) && (board[(dpos + (19 + 1))] == 0);
            int down_chain = (board[(dpos + 2*(19 + 1))] != 3) && (board[(dpos + 2*(19 + 1))] == color) && (mn[(dpos + 2*(19 + 1))] != 1);
            int down_sides = (board[(dpos + (19 + 1) + 1)] != 3) && (board[(dpos + (19 + 1) + 1)] != other) &&
                             (board[(dpos + (19 + 1) - 1)] != 3) && (board[(dpos + (19 + 1) - 1)] != other);

            int right_ok = (board[(dpos + 1)] != 3) && (board[(dpos + 1)] == 0);
            int right_chain = (board[(dpos + 2)] != 3) && (board[(dpos + 2)] == color) && (mn[(dpos + 2)] != 1);
            int right_sides = (board[(dpos + 1 - (19 + 1))] != 3) && (board[(dpos + 1 - (19 + 1))] != other) &&
                              (board[(dpos + 1 + (19 + 1))] != 3) && (board[(dpos + 1 + (19 + 1))] != other);

            int left_ok = (board[(dpos - 1)] != 3) && (board[(dpos - 1)] == 0);
            int left_chain = (board[(dpos - 2)] != 3) && (board[(dpos - 2)] == color) && (mn[(dpos - 2)] != 1);
            int left_sides = (board[(dpos - 1 - (19 + 1))] != 3) && (board[(dpos - 1 - (19 + 1))] != other) &&
                             (board[(dpos - 1 + (19 + 1))] != 3) && (board[(dpos - 1 + (19 + 1))] != other);

            if ((up_ok && up_chain && up_sides) ||
                (down_ok && down_chain && down_sides) ||
                (right_ok && right_chain && right_sides) ||
                (left_ok && left_chain && left_sides)) {
                surrounded = 0;
            }
        } else {
            // Skip further checks if condition not met
            continue;
        }
    }
}
