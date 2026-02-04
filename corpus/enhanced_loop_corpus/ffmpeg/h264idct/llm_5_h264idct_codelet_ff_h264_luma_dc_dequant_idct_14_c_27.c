#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int temp[16];
extern int32_t *input;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 4; i++) {
        const int a0 = input[4 * i + 0];
        const int a1 = input[4 * i + 1];
        const int a2 = input[4 * i + 2];
        const int a3 = input[4 * i + 3];

        if (a0 >= a1 && a2 <= a3) {
            temp[4 * i + 0] = (a0 + a1) + (a2 + a3);
            temp[4 * i + 1] = (a0 + a1) - (a2 + a3);
            temp[4 * i + 2] = (a0 - a1) - (a2 - a3);
            temp[4 * i + 3] = (a0 - a1) + (a2 - a3);
        } else {
            temp[4 * i + 0] = a0;
            temp[4 * i + 1] = a1;
            temp[4 * i + 2] = a2;
            temp[4 * i + 3] = a3;
        }
    }
}
