#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int w2;
extern int x;
extern int16_t *b;
extern int16_t *temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (x = 1; x < w2 - 3; x++) {
    int acc1 = b[x + w2 - 1] + b[x + w2];
    int scaled1 = (1817 * acc1 + 2048) >> 12;
    temp[x] = (unsigned int)(b[x]) - scaled1;

    int acc2 = temp[x - 1] + temp[x];
    int scaled2 = (113 * acc2 + 64) >> 7;
    temp[x + w2 - 1] = (unsigned int)(b[x + w2 - 1]) - scaled2;

    // Add extra computation to increase intensity
    if (x > 1) {
        int diff = temp[x] - temp[x - 1];
        temp[x] += (diff * 3) >> 2;
    }
}
}
