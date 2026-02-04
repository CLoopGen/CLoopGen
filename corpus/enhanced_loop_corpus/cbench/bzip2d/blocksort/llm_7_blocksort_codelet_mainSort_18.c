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
    // Variant 2: Introduce artificial loop-carried dependence by accumulating a local value that depends on previous iterations
    // Also reorders updates to ftab and ptr to create a WAW (write-after-write) hazard on ftab[s], forcing serialization.
    UInt16 temp_s = s;
    for (; i >= 3; i -= 4) {
        // Process in reverse order to create different dependency pattern
        s = (temp_s >> 8) | (block[i - 3] << 8);
        j = ftab[s] - 1;
        ftab[s] = j + 1; // Write with delayed commit
        ptr[j] = i - 3;
        ftab[s] = j; // Second write creates WAW, carried across loop if same s repeats

        s = (s >> 8) | (block[i - 2] << 8);
        j = ftab[s] - 1;
        ftab[s] = j + 1;
        ptr[j] = i - 2;
        ftab[s] = j;

        s = (s >> 8) | (block[i - 1] << 8);
        j = ftab[s] - 1;
        ftab[s] = j + 1;
        ptr[j] = i - 1;
        ftab[s] = j;

        s = (s >> 8) | (block[i] << 8);
        j = ftab[s] - 1;
        ftab[s] = j + 1;
        ptr[j] = i;
        ftab[s] = j;

        temp_s = s; // Carry forward updated s for next major iteration
    }
    s = temp_s;
}
