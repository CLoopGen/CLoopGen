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
for (x = 2; x < 2 * w2; x += 2) {
    int offset = x / 2;
    b2 = ((unsigned int)(temp[offset]) + ((int)(217 * (temp[offset + w2 - 1] + (unsigned int)temp[offset + w2]) + 2048) >> 12));
    b1 = ((unsigned int)(temp[offset + w2 - 1]) + ((int)(6497 * (b0 + (unsigned int)b2) + 2048) >> 12));
    b[x - 1] = ~((~b1) >> 1);
    b[x] = ~((~b2) >> 1);
    b0 = b2;
}
}
