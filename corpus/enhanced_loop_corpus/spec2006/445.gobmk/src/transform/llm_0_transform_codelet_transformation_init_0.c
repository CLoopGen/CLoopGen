#include <stdio.h>

#include <inttypes.h>

extern int transformation[1369][8];
extern const int transformation2[8][2][2];
extern int k;
extern int dx;
extern int dy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (k = 0; k < 8; k++) {
    for (dy = -18; dy <= 18; dy++) {
        for (dx = -18; dx <= 18; dx++) {
            int tx = transformation2[k][0][0] * dx + transformation2[k][0][1] * dy;
            int ty = transformation2[k][1][0] * dx + transformation2[k][1][1] * dy;
            transformation[(dy + 18) * 37 + (dx + 18)][k] = tx * 20 + ty;
        }
    }
}
}
