#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int x;
extern  int w2;
extern int32_t *b;
extern int32_t *tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (x = 2; x < w2 - 1; x += 2) {
    int val1 = b[x + w2 - 1];
    int val2 = b[x + w2];
    int sum = val1 + val2 + 3;
    int avg = (unsigned int)((int)sum >> 2);
    tmp[x] = b[x] - avg;
    tmp[x + 1] = b[x + 1] - ((unsigned int)((int)(b[x + 1 + w2 - 1] + b[x + 1 + w2] + 3) >> 2));
}
}
