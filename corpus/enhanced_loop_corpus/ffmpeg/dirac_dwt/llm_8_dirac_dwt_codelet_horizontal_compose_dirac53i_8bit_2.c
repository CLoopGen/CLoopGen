#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int x;
extern  int w2;
extern int16_t *b;
extern int16_t *temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (x = 2; x < w2 - 1; x += 2) {
    temp[x] = (b[x] - ((unsigned int)((int)(b[x + w2 - 1] + b[x + w2] + b[x + w2 + 1] + 3) >> 2)));
    temp[x + 1] = (b[x + 1] - ((unsigned int)((int)(b[x + w2] + b[x + w2 + 1] + b[x + w2 + 2] + 3) >> 2)));
    temp[x + w2 - 1] = (b[x + w2 - 1] + ((unsigned int)((int)(temp[x - 1] + temp[x] + temp[x + 1] + 2) >> 2)));
    temp[x + w2] = (b[x + w2] + ((unsigned int)((int)(temp[x] + temp[x + 1] + temp[x + 2] + 2) >> 2)));
}
}
