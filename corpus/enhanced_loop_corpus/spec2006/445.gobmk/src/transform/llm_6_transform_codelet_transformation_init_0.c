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
        int base_k = (2 * 19 - 1) * (38 - 1); // Precomputed base offset dependent on k
        for (dy = -18; dy <= 18; dy++) {
            int ty_base;
            int coeff_dy_00 = transformation2[k][0][1];
            int coeff_dy_11 = transformation2[k][1][1];
            for (dx = -18; dx <= 18; dx++) {
                int tx = transformation2[k][0][0] * dx + coeff_dy_00 * dy;
                int ty = transformation2[k][1][0] * dx + coeff_dy_11 * dy;
                int index = (dy + 18) * (2 * 19 - 1) + (dx + 18);
                // Introduce WAW dependency by writing to same location in non-constant order
                // but ensure correctness via ordered access
                transformation[index][k] = tx * 20 + ty;
            }
        }
    }
}
