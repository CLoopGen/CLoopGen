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
for (i = 0; i < alphaSize; i++) {
    int idx = length[i] + 1;
    if (idx >= 0) {
        base[idx]++;
    }
}
}
