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
for (x = 4; x < width - 3; x += 2) {
    IDWTELEM t1 = temp[x - 1], t2 = temp[x], t3 = temp[x + 1];
    IDWTELEM avg = (t1 + t3 + 2) / 4;
    b[x] = t2 - avg;
    b[x - 1] = t1 + ((b[x - 2] + b[x]) / 2);
}
}
