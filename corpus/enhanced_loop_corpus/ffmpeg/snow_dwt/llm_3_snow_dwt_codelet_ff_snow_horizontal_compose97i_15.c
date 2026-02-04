#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef short IDWTELEM;

extern IDWTELEM *b;
extern IDWTELEM *temp;
extern int width;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (x = 2; x < width - 1; x += 4) {
    int idx1 = x;
    int idx2 = x + 2;
    if (idx2 < width - 1) {
        b[idx1] = temp[idx1] + ((4 * temp[idx1] + temp[idx1 - 1] + temp[idx1 + 1] + 8) >> 4);
        b[idx1 - 1] = temp[idx1 - 1] + ((3 * (b[idx1 - 2] + b[idx1])) >> 1);
        b[idx2] = temp[idx2] + ((4 * temp[idx2] + temp[idx2 - 1] + temp[idx2 + 1] + 8) >> 4);
        b[idx2 - 1] = temp[idx2 - 1] + ((3 * (b[idx2 - 2] + b[idx2])) >> 1);
    } else {
        b[idx1] = temp[idx1] + ((4 * temp[idx1] + temp[idx1 - 1] + temp[idx1 + 1] + 8) >> 4);
        b[idx1 - 1] = temp[idx1 - 1] + ((3 * (b[idx1 - 2] + b[idx1])) >> 1);
    }
}
}
