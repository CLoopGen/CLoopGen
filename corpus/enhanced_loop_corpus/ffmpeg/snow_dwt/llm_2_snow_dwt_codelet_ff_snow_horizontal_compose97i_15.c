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
for (x = 2; x < width - 1; x += 2) {
    int idx = x;
    b[idx] = temp[idx] + ((4 * temp[idx] + temp[idx - 1] + temp[idx + 1] + 8) >> 4);
    b[idx - 1] = temp[idx - 1] + ((3 * (b[idx - 2] + b[idx])) >> 1);
}
}
