#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *input;
extern int i;
extern int temp[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 4; i++) {
    const int x0 = input[4 * i + 0];
    const int x1 = input[4 * i + 1];
    const int x2 = input[4 * i + 2];
    const int x3 = input[4 * i + 3];
    const int sum = x0 + x2;
    const int diff = x0 - x2;
    const int y1 = 7 * x1 - 17 * x3;
    const int y3 = 17 * x1 + 7 * x3;

    if (sum > 0) {
        temp[4 * i + 0] = 13 * sum + y3;
        temp[4 * i + 3] = 13 * sum - y3;
    } else {
        temp[4 * i + 0] = 13 * sum - y3;
        temp[4 * i + 3] = 13 * sum + y3;
    }

    if (diff >= 0) {
        temp[4 * i + 1] = 13 * diff + y1;
        temp[4 * i + 2] = 13 * diff - y1;
    } else {
        temp[4 * i + 1] = 13 * diff - y1;
        temp[4 * i + 2] = 13 * diff + y1;
    }
}
}
