#include <stdio.h>

#include <inttypes.h>

extern int transformation[1369][8];
extern const int transformation2[8][2][2];
extern int k;
extern int dx;
extern int dy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (k = 0; k < 8; k += 2) {
    for (dy = -10; dy <= 10; dy++) {
        for (dx = -10; dx <= 10; dx++) {
            int tx1 = transformation2[k][0][0] * dx + transformation2[k][0][1] * dy;
            int ty1 = transformation2[k][1][0] * dx + transformation2[k][1][1] * dy;
            transformation[(dy + 10) * 21 + (dx + 10)][k] = tx1 * 20 + ty1;
            if (k + 1 < 8) {
                int tx2 = transformation2[k+1][0][0] * dx + transformation2[k+1][0][1] * dy;
                int ty2 = transformation2[k+1][1][0] * dx + transformation2[k+1][1][1] * dy;
                transformation[(dy + 10) * 21 + (dx + 10)][k+1] = tx2 * 20 + ty2;
            }
        }
    }
}
}
