#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *coef;
extern int y;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Strided memory access: process every second element in a zigzag-like pattern, then cover all
    static const int indices[4][4] = {
        {0, 2, 1, 3},
        {6, 4, 7, 5},
        {8, 10, 9, 11},
        {14, 12, 15, 13}
    };
    for (y = 0; y < 4; y++) {
        for (x = 0; x < 4; x++) {
            static const int scale[] = {13107 * 10, 8066 * 13, 5243 * 16};
            const int pos = indices[y][x];
            const int idx = ((pos / 4) & 1) + ((pos % 4) & 1);
            coef[pos] = (coef[pos] * scale[idx] + (1 << 14)) >> 15;
        }
    }
}
