#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *s1;
extern uint8_t *s2;
extern ptrdiff_t stride;
extern int h;
extern int score1;
extern int score2;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < h; y++) {
    for (x = 0; x < 8; x++)
        score1 += (s1[x] - s2[x]) * (s1[x] - s2[x]);
    if (y + 1 >= h) continue;
    for (x = 0; x < 7; x++) {
        int val1 = s1[x] - s1[x + stride] - s1[x + 1] + s1[x + stride + 1];
        int val2 = s2[x] - s2[x + stride] - s2[x + 1] + s2[x + stride + 1];
        score2 += (val1 < 0 ? -val1 : val1) - (val2 < 0 ? -val2 : val2);
    }
    s1 += stride;
    s2 += stride;
}
}
