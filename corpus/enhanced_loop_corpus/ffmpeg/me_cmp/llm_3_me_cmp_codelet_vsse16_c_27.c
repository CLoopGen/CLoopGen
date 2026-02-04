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



void loop() {
    for (y = 1; y < h; y++) {
        uint8_t *ptr1 = s1;
        uint8_t *ptr2 = s2;
        for (x = 0; x < 16; x++) {
            ptrdiff_t idx = x * 2; // Strided access with step of 2 elements
            if (idx < 16) {
                int temp = (ptr1[idx] - ptr2[idx] - ptr1[idx + stride] + ptr2[idx + stride]);
                score += temp * temp;
            }
        }
        s1 += stride;
        s2 += stride;
    }
}
