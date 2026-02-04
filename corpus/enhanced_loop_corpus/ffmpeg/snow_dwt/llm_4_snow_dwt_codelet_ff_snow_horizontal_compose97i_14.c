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
for (x = 1; x < (width >> 1); x++) {
    if ((b[x + w2 - 1] + b[x + w2]) >= 0) {
        temp[2 * x] = b[x] - ((3 * (b[x + w2 - 1] + b[x + w2]) + 4) >> 3);
    } else {
        temp[2 * x] = b[x];
    }
    temp[2 * x - 1] = b[x + w2 - 1] - temp[2 * x - 2] - temp[2 * x];
}
}
