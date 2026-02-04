#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *s;
extern ptrdiff_t stride;
extern int h;
extern int score;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    for (y = 1; y < h; y++) {
        uint8_t *row_current = s;
        uint8_t *row_prev = s - stride;
        for (x = 0; x < 16; x += 4) {
            score += ((row_current[x] - row_prev[x]) * (row_current[x] - row_prev[x])) +
                     ((row_current[x + 1] - row_prev[x + 1]) * (row_current[x + 1] - row_prev[x + 1])) +
                     ((row_current[x + 2] - row_prev[x + 2]) * (row_current[x + 2] - row_prev[x + 2])) +
                     ((row_current[x + 3] - row_prev[x + 3]) * (row_current[x + 3] - row_prev[x + 3]));
        }
        s += stride;
    }
}
