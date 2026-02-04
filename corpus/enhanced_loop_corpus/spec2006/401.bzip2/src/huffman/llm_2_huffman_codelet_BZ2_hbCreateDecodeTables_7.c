#include <stdio.h>

#include <inttypes.h>

typedef int Int32;

typedef unsigned char UChar;

extern Int32 *base;
extern UChar *length;
extern Int32 alphaSize;
extern Int32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access pattern
    // Instead of accessing length[0], length[1], ..., we access with a stride of 2 (unrolled-like pattern)
    // To maintain correctness, we handle even and odd indices in separate passes if needed.
    // Here, we simulate strided access by stepping through indices with increment of 2
    for (i = 0; i < alphaSize; i += 2) {
        if (i < alphaSize) {
            base[length[i] + 1]++;
        }
        if (i + 1 < alphaSize) {
            base[length[i + 1] + 1]++;
        }
    }
}
