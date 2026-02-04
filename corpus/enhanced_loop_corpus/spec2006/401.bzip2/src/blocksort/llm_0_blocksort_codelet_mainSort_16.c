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
    for (int depth1 = 0; depth1 < 4; depth1++) {
        for (i = 0; i < (2 + 12 + 18 + 2) / 4 + (depth1 < (2 + 12 + 18 + 2) % 4 ? 1 : 0); i++) {
            int index = depth1 * ((2 + 12 + 18 + 2) / 4 + 1) + i;
            if (index < (2 + 12 + 18 + 2)) {
                block[nblock + index] = block[index];
                quadrant[nblock + index] = 0;
            }
        }
    }
}
