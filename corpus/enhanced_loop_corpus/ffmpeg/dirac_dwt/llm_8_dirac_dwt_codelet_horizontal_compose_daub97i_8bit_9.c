#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int w2;
extern int x;
extern int b0;
extern int b1;
extern int b2;
extern int16_t *b;
extern int16_t *temp;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    for (x = 2; x < w2 - 1; x += 2) {
        int16_t t0 = temp[x];
        int16_t t1 = temp[x + w2 - 1];
        int16_t t2 = temp[x + w2];
        int16_t t3 = temp[x + 1];
        int16_t t4 = temp[x + w2 + 1];

        int val2a = (int)(217 * (t1 + t2) + 2048) >> 12;
        int val2b = (int)(217 * (t3 + t4) + 2048) >> 12;

        b2 = ((unsigned int)t0 + val2a);
        int b2_next = ((unsigned int)t3 + val2b);

        int val1a = (int)(6497 * (b0 + b2) + 2048) >> 12;
        int val1b = (int)(6497 * (b2 + b2_next) + 2048) >> 12;

        b1 = ((unsigned int)t1 + val1a);
        int b1_next = ((unsigned int)t2 + val1b);

        b[2 * x - 1] = ~((~b1) >> 1);
        b[2 * x] = ~((~b2) >> 1);
        b[2 * x + 1] = ~((~b1_next) >> 1);
        b[2 * x + 2] = ~((~b2_next) >> 1);

        b0 = b2_next;
        x++; 
    }
}
