#include <stdio.h>

#include <inttypes.h>

extern unsigned short **imY;
extern int x_pos;
extern int x;
extern int maxold_x;
extern int result;
extern int pres_x;
extern int pres_y;
extern  int COEF[6];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided Memory Access Pattern
    // Introduce a fixed stride when accessing imY columns to simulate non-unit stride access,
    // which may model subsampling or strided data traversal.
    const int STRIDE = 2;
    result = 0;
    for (x = -2; x < 4; x += 1) {
        int raw_x = x_pos + x * STRIDE; // Apply stride on the input offset
        pres_x = (raw_x < 0) ? 0 : ((raw_x > maxold_x) ? maxold_x : raw_x);
        result += imY[pres_y][pres_x] * COEF[x + 2];
    }
}
