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
        if (width > 4) {
            b[x] = temp[x] - ((temp[x - 1] + temp[x + 1] + 2) >> 2);
            if (x >= 3) {
                b[x - 1] = temp[x - 1] + ((b[x - 2] + b[x] + 1) >> 1);
            }
        }
    }
}
