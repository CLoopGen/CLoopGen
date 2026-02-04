#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef short IDWTELEM;

extern IDWTELEM *b;
extern IDWTELEM *temp;
extern int width;
extern  int w2;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (x = 2; x < (width >> 1); x += 2) {
    IDWTELEM val1 = b[x] - ((5 * (b[x + w2 - 1] + b[x + w2]) + 8) >> 4);
    temp[2 * x] = val1;
    temp[2 * x - 1] = b[x + w2 - 1] - temp[2 * x - 2] - temp[2 * x];
    if (x + 1 < (width >> 1)) {
        IDWTELEM val2 = b[x + 1] - ((5 * (b[x + w2] + b[x + w2 + 1]) + 8) >> 4);
        temp[2 * (x + 1)] = val2;
        temp[2 * (x + 1) - 1] = b[x + w2] - temp[2 * x] - temp[2 * (x + 1)];
    }
}
}
