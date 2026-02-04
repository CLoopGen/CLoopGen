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



void loop(){
for (y = 1; y < h; y++) {
    uint8_t *row = s;
    uint8_t *prev_row = s - stride;
    for (x = 0; x < 8; x += 4) {
        score += abs((int)(row[x] - prev_row[x])) +
                 abs((int)(row[x + 1] - prev_row[x + 1])) +
                 abs((int)(row[x + 2] - prev_row[x + 2])) +
                 abs((int)(row[x + 3] - prev_row[x + 3]));
    }
    s += stride;
}
}
