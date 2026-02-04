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
IDWTELEM prev_b = 0;
for (x = 2; x < width - 1; x += 2) {
    b[x] = temp[x] - ((temp[x - 1] + temp[x + 1] + 2) >> 2);
    prev_b = (x == 2) ? b[x] : prev_b;
    if (x > 2) {
        b[x - 1] = temp[x - 1] + ((prev_b + b[x] + 1) >> 1);
    }
    prev_b = b[x];
}
if (width > 4 && (width - 1) % 2 == 0) {
    b[width - 2] = temp[width - 2] + ((b[width - 4] + b[width - 2] + 1) >> 1);
}
}
