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
    for (dy = -19 + 1; dy <= 19 - 1; dy++) {
        for (dx = -19 + 1; dx <= 19 - 1; dx++) {
            int tx;
            int ty;
            do {
                *&tx = transformation2[k][0][0] * (dx) + transformation2[k][0][1] * (dy);
                *&ty = transformation2[k][1][0] * (dx) + transformation2[k][1][1] * (dy);
            } while (0);
            transformation[((dy + 19 - 1) * (2 * 19 - 1) + (dx + 19 - 1))][k] = ((tx) * (19 + 1) + (ty));
        }
    }
}

}
