#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int temp[64];
extern int sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Flatten the original structure by increasing outer loop depth and removing internal blocks as independent iterations
for (int k = 0; k < 8 * 8; k++) {
    i = k % 8;
    int stage = k / 8;

    if (stage == 0) {
        int a = temp[8 * 0 + i], b = temp[8 * 1 + i];
        temp[8 * 0 + i] = a + b;
        temp[8 * 1 + i] = a - b;
    }
    else if (stage == 1) {
        int a = temp[8 * 2 + i], b = temp[8 * 3 + i];
        temp[8 * 2 + i] = a + b;
        temp[8 * 3 + i] = a - b;
    }
    else if (stage == 2) {
        int a = temp[8 * 4 + i], b = temp[8 * 5 + i];
        temp[8 * 4 + i] = a + b;
        temp[8 * 5 + i] = a - b;
    }
    else if (stage == 3) {
        int a = temp[8 * 6 + i], b = temp[8 * 7 + i];
        temp[8 * 6 + i] = a + b;
        temp[8 * 7 + i] = a - b;
    }
    else if (stage == 4) {
        int a = temp[8 * 0 + i], b = temp[8 * 2 + i];
        temp[8 * 0 + i] = a + b;
        temp[8 * 2 + i] = a - b;
    }
    else if (stage == 5) {
        int a = temp[8 * 1 + i], b = temp[8 * 3 + i];
        temp[8 * 1 + i] = a + b;
        temp[8 * 3 + i] = a - b;
    }
    else if (stage == 6) {
        int a = temp[8 * 4 + i], b = temp[8 * 6 + i];
        temp[8 * 4 + i] = a + b;
        temp[8 * 6 + i] = a - b;
    }
    else if (stage == 7) {
        int a = temp[8 * 5 + i], b = temp[8 * 7 + i];
        temp[8 * 5 + i] = a + b;
        temp[8 * 7 + i] = a - b;
    }

    // Accumulate sum only in the last stage
    if (stage == 7) {
        sum += ((((temp[8 * 0 + i]) + (temp[8 * 4 + i])) >= 0 ? ((temp[8 * 0 + i]) + (temp[8 * 4 + i])) : (-((temp[8 * 0 + i]) + (temp[8 * 4 + i])))) +
               (((temp[8 * 0 + i]) - (temp[8 * 4 + i])) >= 0 ? ((temp[8 * 0 + i]) - (temp[8 * 4 + i])) : (-((temp[8 * 0 + i]) - (temp[8 * 4 + i]))))) +
               ((((temp[8 * 1 + i]) + (temp[8 * 5 + i])) >= 0 ? ((temp[8 * 1 + i]) + (temp[8 * 5 + i])) : (-((temp[8 * 1 + i]) + (temp[8 * 5 + i])))) +
                (((temp[8 * 1 + i]) - (temp[8 * 5 + i])) >= 0 ? ((temp[8 * 1 + i]) - (temp[8 * 5 + i])) : (-((temp[8 * 1 + i]) - (temp[8 * 5 + i]))))) +
               ((((temp[8 * 2 + i]) + (temp[8 * 6 + i])) >= 0 ? ((temp[8 * 2 + i]) + (temp[8 * 6 + i])) : (-((temp[8 * 2 + i]) + (temp[8 * 6 + i])))) +
                (((temp[8 * 2 + i]) - (temp[8 * 6 + i])) >= 0 ? ((temp[8 * 2 + i]) - (temp[8 * 6 + i])) : (-((temp[8 * 2 + i]) - (temp[8 * 6 + i]))))) +
               ((((temp[8 * 3 + i]) + (temp[8 * 7 + i])) >= 0 ? ((temp[8 * 3 + i]) + (temp[8 * 7 + i])) : (-((temp[8 * 3 + i]) + (temp[8 * 7 + i])))) +
                (((temp[8 * 3 + i]) - (temp[8 * 7 + i])) >= 0 ? ((temp[8 * 3 + i]) - (temp[8 * 7 + i])) : (-((temp[8 * 3 + i]) - (temp[8 * 7 + i])))));
    }
}
}
