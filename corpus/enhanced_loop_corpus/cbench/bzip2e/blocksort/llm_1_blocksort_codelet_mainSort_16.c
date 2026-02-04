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
    for (i = 0; i < (2 + 12 + 18 + 2); i += 4) {
        for (Int32 step = 0; step < 4 && (i + step) < (2 + 12 + 18 + 2); step++) {
            Int32 idx = i + step;
            block[nblock + idx] = block[idx];
            quadrant[nblock + idx] = 0;
        }
    }
}
