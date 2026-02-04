#include <stdio.h>

#include <inttypes.h>

typedef int Int32;

typedef unsigned char UChar;

extern char *outbuf;
extern Int32 i;
extern UChar buf[32];
extern Int32 nBuf;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index map (simulated via reversed index array)
    Int32 indices[32];
    Int32 j;
    for (j = 0; j < nBuf; j++) {
        indices[j] = nBuf - j - 1;
    }
    for (j = 0; j < nBuf; j++) {
        outbuf[j] = buf[indices[j]];
    }
}
