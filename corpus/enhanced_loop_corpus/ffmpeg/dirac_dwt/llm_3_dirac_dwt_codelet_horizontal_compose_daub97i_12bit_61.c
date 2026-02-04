#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int w2;
extern int x;
extern int b0;
extern int b1;
extern int b2;
extern int32_t *b;
extern int32_t *temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (x = 2; x < w2; x += 2) {
    int offset = w2;
    int idx1 = x - 1;
    int idx2 = x;
    b2 = ((unsigned int)(temp[idx1]) + ((int)(217 * (temp[idx1 + offset - 1] + (unsigned int)temp[idx1 + offset]) + 2048) >> 12));
    b1 = ((unsigned int)(temp[idx1 + offset - 1]) + ((int)(6497 * (b0 + (unsigned int)b2) + 2048) >> 12));
    b[2 * idx1 - 1] = ~((~b1) >> 1);
    b[2 * idx1] = ~((~b2) >> 1);
    b0 = b2;

    if (x + 1 < w2) {
        int idx3 = x + 1;
        int b2_next = ((unsigned int)(temp[idx3]) + ((int)(217 * (temp[idx3 + offset - 1] + (unsigned int)temp[idx3 + offset]) + 2048) >> 12));
        int b1_next = ((unsigned int)(temp[idx3 + offset - 1]) + ((int)(6497 * (b0 + (unsigned int)b2_next) + 2048) >> 12));
        b[2 * idx3 - 1] = ~((~b1_next) >> 1);
        b[2 * idx3] = ~((~b2_next) >> 1);
        b0 = b2_next;
    }
}
}
