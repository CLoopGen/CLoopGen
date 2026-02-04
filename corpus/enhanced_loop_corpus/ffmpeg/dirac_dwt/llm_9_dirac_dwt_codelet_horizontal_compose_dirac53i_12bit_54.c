#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int x;
extern  int w2;
extern int32_t *b;
extern int32_t *temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (x = 1; x < w2 - 2; x++) {
    int sum1 = b[x + w2 - 1] + b[x + w2];
    temp[x] = b[x] - ((sum1 + 2) >> 2);
    int avg_temp = (temp[x - 1] + temp[x] + 1) >> 1;
    temp[x + w2 - 1] = b[x + w2 - 1] + avg_temp;
    temp[x + w2] = b[x + w2] + ((temp[x] + temp[x + 1] + 1) >> 1);
}
}
