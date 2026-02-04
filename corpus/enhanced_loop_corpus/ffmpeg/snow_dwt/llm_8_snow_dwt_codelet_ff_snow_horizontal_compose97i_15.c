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
for (x = 1; x < width - 2; x += 3) {
    IDWTELEM t0 = temp[x];
    IDWTELEM t1 = temp[x + 1];
    IDWTELEM t2 = temp[x - 1];
    int sum = 5 * t0 + t1 + t2;
    b[x] = t0 + ((sum + 8) >> 4);
    if (x >= 2) {
        b[x - 1] = t2 + ((b[x - 2] + b[x]) * 3 >> 1);
    }
}
}
