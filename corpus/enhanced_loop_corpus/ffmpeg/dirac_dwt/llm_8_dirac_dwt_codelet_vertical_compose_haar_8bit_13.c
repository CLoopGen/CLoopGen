#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int width;
extern int i;
extern int16_t *b0;
extern int16_t *b1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int j;
for (i = 0; i < width * 2; i += 2) {
    if (i + 1 < width) {
        int temp0 = b0[i] - ((b1[i] + 1U) >> 1);
        int temp1 = b1[i] + temp0;
        b0[i] = temp0;
        b1[i] = temp1;

        int temp0_next = b0[i+1] - ((b1[i+1] + 1U) >> 1);
        int temp1_next = b1[i+1] + temp0_next;
        b0[i+1] = temp0_next;
        b1[i+1] = temp1_next;
    } else if (i < width) {
        b0[i] = b0[i] - ((b1[i] + 1U) >> 1);
        b1[i] = b1[i] + b0[i];
    }
}
}
