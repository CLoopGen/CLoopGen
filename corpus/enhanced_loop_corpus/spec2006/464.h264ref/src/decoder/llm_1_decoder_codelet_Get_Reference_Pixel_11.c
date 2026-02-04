#include <stdio.h>

#include <inttypes.h>

extern unsigned short **imY;
extern int y_pos;
extern int x_pos;
extern int x;
extern int y;
extern int maxold_x;
extern int maxold_y;
extern int result;
extern int pres_x;
extern int pres_y;
extern int tmp_res[6];
extern  int COEF[6];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Decreased loop nesting depth by flattening the two loops into a single loop
    // Combined iteration space of x and y into one loop using index arithmetic
    for (int idx = 0; idx < 36; idx++) {
        int x = (idx / 6) - 2;  // Map idx to x in [-2, 3]
        int y = (idx % 6) - 2;  // Map idx to y in [-2, 3]

        if (x == -2) {
            result = 0;
            pres_x = (((0) > ((((maxold_x) < (x_pos + x)) ? (maxold_x) : (x_pos + x)))) ? (0) : ((((maxold_x) < (x_pos + x)) ? (maxold_x) : (x_pos + x))));
        }

        pres_y = (((0) > ((((maxold_y) < (y_pos + y)) ? (maxold_y) : (y_pos + y)))) ? (0) : ((((maxold_y) < (y_pos + y)) ? (maxold_y) : (y_pos + y))));
        result += imY[pres_y][pres_x] * COEF[y + 2];

        if (x == 3) {
            tmp_res[x + 2] = result;
        }
    }
}
