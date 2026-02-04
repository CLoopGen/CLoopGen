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
        for (int offset = 0; offset < 2 && (x + offset) < width - 1; offset++) {
            int idx = x + offset;
            b[idx] = temp[idx] - ((temp[idx - 1] + temp[idx + 1] + 2) >> 2);
            b[idx - 1] = temp[idx - 1] + ((b[idx - 2] + b[idx] + 1) >> 1);
        }
    }
}
