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
    // Variant 1: Strided memory access with step size of 2 (forward and backward)
    Int32 step = 2;
    Int32 j;
    for (j = 0; j < nBuf; j += step) {
        outbuf[j] = buf[nBuf - j - 1];
        if (j + 1 < nBuf) {
            outbuf[j + 1] = buf[nBuf - (j + 1) - 1];
        }
    }
}
