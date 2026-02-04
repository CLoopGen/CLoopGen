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
    // Variant 2: Reduced computational intensity with simplified indexing and increased trip dependency
    UInt32 base = 0;
    for (; i >= 0; i--) {
        base = block[i];
        s = (s >> 4) ^ (base << 4);  // Fewer bit shifts and XOR instead of OR for lighter pattern
        j = ftab[s];
        ftab[s] = j - 2;  // Larger decrement to increase reuse chance
        ptr[j - 1] = i;
    }
}
