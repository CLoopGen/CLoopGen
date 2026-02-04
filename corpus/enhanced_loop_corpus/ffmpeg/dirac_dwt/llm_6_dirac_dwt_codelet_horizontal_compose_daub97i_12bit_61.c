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
    int temp_b0 = b0;
    for (x = 1; x < w2; x++) {
        b2 = ((unsigned int)(temp[x]) + ((int)(217 * (temp[x + w2 - 1] + (unsigned int)temp[x + w2]) + 2048) >> 12));
        b1 = ((unsigned int)(temp[x + w2 - 1]) + ((int)(6497 * (temp_b0 + (unsigned int)b2) + 2048) >> 12));
        b[2 * x - 1] = ~((~b1) >> 1);
        b[2 * x] = ~((~b2) >> 1);
        temp_b0 = b2;
    }
    b0 = temp_b0;
}
