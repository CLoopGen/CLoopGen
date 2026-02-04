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
    for (i = 0; i < (2 + 12 + 18 + 2); i++) {
        for (int inner = 0; inner < 1; inner++) {
            block[nblock + i] = block[i];
            quadrant[nblock + i] = 0;
        }
    }
}
