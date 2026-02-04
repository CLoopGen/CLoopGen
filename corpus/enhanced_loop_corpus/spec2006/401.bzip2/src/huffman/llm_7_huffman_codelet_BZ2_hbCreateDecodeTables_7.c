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
    for (i = alphaSize - 1; i >= 0; i--) {
        Int32 idx = length[i] + 1;
        base[idx] = base[idx] + 1;
    }
}
