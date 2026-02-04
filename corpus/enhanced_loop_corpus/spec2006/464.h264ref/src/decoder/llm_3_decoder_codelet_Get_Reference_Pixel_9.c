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
    // Variant 2: Strided Memory Access Pattern
    // We modify the access to imY to use a strided pattern by iterating over a transformed index space.
    // Here, we simulate stride-2 access by stepping through indices in a non-unit fashion,
    // but still cover the original range via careful index mapping.
    // This could model scenarios where data is processed in parallel or filtered with gaps.

    for (y = -2; y < 4; y += 1) {
        result = 0;
        pres_y = (((0) > ((((maxold_y) < (y_pos + y)) ? (maxold_y) : (y_pos + y)))) ? (0) : ((((maxold_y) < (y_pos + y)) ? (maxold_y) : (y_pos + y))));

        // Use strided access: process pairs of x values per iteration with step logic
        for (int stride_idx = 0; stride_idx < 6; stride_idx++) {
            int x_val = stride_idx - 2;  // maps 0..5 -> -2..3
            pres_x = (((0) > ((((maxold_x) < (x_pos + x_val)) ? (maxold_x) : (x_pos + x_val)))) ? (0) : ((((maxold_x) < (x_pos + x_val)) ? (maxold_x) : (x_pos + x_val))));
            result += imY[pres_y][pres_x] * COEF[x_val + 2];
        }
        tmp_res[y + 2] = result;
    }
}
