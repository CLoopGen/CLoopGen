#include <stdio.h>

#include <inttypes.h>

typedef unsigned int UInt32;

typedef unsigned char UChar;

typedef int Int32;

typedef unsigned short UInt16;

extern UInt32 *ptr;
extern UChar *block;
extern UInt32 *ftab;
extern Int32 i;
extern Int32 j;
extern UInt16 s;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
if (i >= 3) {
    // Unroll the loop logic into a deeper sequential structure with conditional checks simulating reduced loop control
    // This variant decreases effective loop nesting by eliminating the for-loop in favor of cascaded if-chains (conceptually flatter control)
    // However, since we must retain a loop and avoid while/do-while, we use a counted for-loop with larger step and internal conditions
    for (; i >= 3; ) {
        if (i >= 3) {
            s = (s >> 8) | (block[i] << 8);
            j = ftab[s] - 1;
            ftab[s] = j;
            ptr[j] = i;
            s = (s >> 8) | (block[i - 1] << 8);
            j = ftab[s] - 1;
            ftab[s] = j;
            ptr[j] = i - 1;
            s = (s >> 8) | (block[i - 2] << 8);
            j = ftab[s] - 1;
            ftab[s] = j;
            ptr[j] = i - 2;
            s = (s >> 8) | (block[i - 3] << 8);
            j = ftab[s] - 1;
            ftab[s] = j;
            ptr[j] = i - 3;
            i -= 4;
        }
    }
}
}
