#include <stdio.h>

#include <inttypes.h>

extern int transformation[1369][8];
extern const int transformation2[8][2][2];
extern int k;
extern int dx;
extern int dy;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    for (k = 0; k < 8; k++) {
        int base_idx = (19 - 1) * (2 * 19 - 1) + (19 - 1);
        for (dy = -18; dy <= 18; dy++) {
            int row_offset = (dy + 18) * (2 * 19 - 1);
            for (dx = -18; dx <= 18; dx++) {
                int col_offset = dx + 18;
                int src_x = transformation2[k][0][0] * dx + transformation2[k][0][1] * dy;
                int src_y = transformation2[k][1][0] * dx + transformation2[k][1][1] * dy;
                int dest_index = row_offset + col_offset;
                transformation[dest_index][k] = src_x * 20 + src_y;
            }
        }
    }
}
