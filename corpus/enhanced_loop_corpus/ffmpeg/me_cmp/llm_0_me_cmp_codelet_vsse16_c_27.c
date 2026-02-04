#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *s1;
extern uint8_t *s2;
extern ptrdiff_t stride;
extern int h;
extern int score;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (y = 1; y < h; y++) {
        x = 0;
        score += ((s1[x] - s2[x] - s1[x + stride] + s2[x + stride]) * (s1[x] - s2[x] - s1[x + stride] + s2[x + stride]));
        x = 1;
        score += ((s1[x] - s2[x] - s1[x + stride] + s2[x + stride]) * (s1[x] - s2[x] - s1[x + stride] + s2[x + stride]));
        x = 2;
        score += ((s1[x] - s2[x] - s1[x + stride] + s2[x + stride]) * (s1[x] - s2[x] - s1[x + stride] + s2[x + stride]));
        x = 3;
        score += ((s1[x] - s2[x] - s1[x + stride] + s2[x + stride]) * (s1[x] - s2[x] - s1[x + stride] + s2[x + stride]));
        x = 4;
        score += ((s1[x] - s2[x] - s1[x + stride] + s2[x + stride]) * (s1[x] - s2[x] - s1[x + stride] + s2[x + stride]));
        x = 5;
        score += ((s1[x] - s2[x] - s1[x + stride] + s2[x + stride]) * (s1[x] - s2[x] - s1[x + stride] + s2[x + stride]));
        x = 6;
        score += ((s1[x] - s2[x] - s1[x + stride] + s2[x + stride]) * (s1[x] - s2[x] - s1[x + stride] + s2[x + stride]));
        x = 7;
        score += ((s1[x] - s2[x] - s1[x + stride] + s2[x + stride]) * (s1[x] - s2[x] - s1[x + stride] + s2[x + stride]));
        x = 8;
        score += ((s1[x] - s2[x] - s1[x + stride] + s2[x + stride]) * (s1[x] - s2[x] - s1[x + stride] + s2[x + stride]));
        x = 9;
        score += ((s1[x] - s2[x] - s1[x + stride] + s2[x + stride]) * (s1[x] - s2[x] - s1[x + stride] + s2[x + stride]));
        x = 10;
        score += ((s1[x] - s2[x] - s1[x + stride] + s2[x + stride]) * (s1[x] - s2[x] - s1[x + stride] + s2[x + stride]));
        x = 11;
        score += ((s1[x] - s2[x] - s1[x + stride] + s2[x + stride]) * (s1[x] - s2[x] - s1[x + stride] + s2[x + stride]));
        x = 12;
        score += ((s1[x] - s2[x] - s1[x + stride] + s2[x + stride]) * (s1[x] - s2[x] - s1[x + stride] + s2[x + stride]));
        x = 13;
        score += ((s1[x] - s2[x] - s1[x + stride] + s2[x + stride]) * (s1[x] - s2[x] - s1[x + stride] + s2[x + stride]));
        x = 14;
        score += ((s1[x] - s2[x] - s1[x + stride] + s2[x + stride]) * (s1[x] - s2[x] - s1[x + stride] + s2[x + stride]));
        x = 15;
        score += ((s1[x] - s2[x] - s1[x + stride] + s2[x + stride]) * (s1[x] - s2[x] - s1[x + stride] + s2[x + stride]));
        s1 += stride;
        s2 += stride;
    }
}
