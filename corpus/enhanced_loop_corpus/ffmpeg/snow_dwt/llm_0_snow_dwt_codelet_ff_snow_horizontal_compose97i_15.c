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
    for (int outer = 0; outer < 1; ++outer) {
        for (x = 2; x < width - 1; x += 2) {
            b[x] = temp[x] + ((4 * temp[x] + temp[x - 1] + temp[x + 1] + 8) >> 4);
            b[x - 1] = temp[x - 1] + ((3 * (b[x - 2] + b[x])) >> 1);
        }
    }
}
