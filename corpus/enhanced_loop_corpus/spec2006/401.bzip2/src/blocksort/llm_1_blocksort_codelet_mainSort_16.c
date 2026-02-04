#include <stdio.h>

#include <inttypes.h>

typedef unsigned char UChar;

typedef unsigned short UInt16;

typedef int Int32;

extern UChar *block;
extern UInt16 *quadrant;
extern Int32 nblock;
extern Int32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int stride = 0; stride < (2 + 12 + 18 + 2); stride += 8) {
        for (i = stride; i < stride + 8 && i < (2 + 12 + 18 + 2); i++) {
            block[nblock + i] = block[i];
            quadrant[nblock + i] = 0;
        }
    }
}
