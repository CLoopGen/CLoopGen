#include <stdio.h>

#include <inttypes.h>

extern int transformation[1369][8];
extern const int transformation2[8][2][2];
extern int k;
extern int dx;
extern int dy;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Indirect memory access using precomputed indices
    int index_map[37*37];
    int idx = 0;
    for (int i = -18; i <= 18; i++) {
        for (int j = -18; j <= 18; j++) {
            index_map[idx++] = (i + 18) * (2 * 19 - 1) + (j + 18);
        }
    }

    for (k = 0; k < 8; k++) {
        int map_idx = 0;
        for (dy = -18; dy <= 18; dy++) {
            for (dx = -18; dx <= 18; dx++) {
                int tx = transformation2[k][0][0] * dx + transformation2[k][0][1] * dy;
                int ty = transformation2[k][1][0] * dx + transformation2[k][1][1] * dy;
                int linear_index = index_map[map_idx];
                transformation[linear_index][k] = tx * 20 + ty;
                map_idx++;
            }
        }
    }
}
