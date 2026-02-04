#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int x;
extern  int w2;
extern int16_t *b;
extern int16_t *tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (x = 1; x < w2; x++) {
    int avg = (int)(b[x + w2 - 1] + (unsigned int)(b[x + w2]) + 1) >> 1;
    avg = (avg + (unsigned int)(b[x + w2 + 1]) + 1) >> 1;
    tmp[x] = b[x] - ((unsigned int)((avg + 1) >> 1));
}
}
