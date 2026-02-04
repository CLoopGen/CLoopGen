#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int w2;
extern int x;
extern int16_t *b;
extern int16_t *tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (x = 4; x < w2 - 3; x += 2) {
    int val1 = (int)(9U * b[x + w2 - 1] + 9U * b[x + w2]);
    int val2 = (int)(b[x + w2 + 1] + b[x + w2 - 2]);
    tmp[x] = (int)(((unsigned int)(b[x]) - ((val1 - val2 + 16) >> 5)));
}
}
