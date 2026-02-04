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
    Int32 j;
    for (j = 0; j < nBuf; j++) {
        Int32 idx = nBuf - j - 1;
        outbuf[j] = buf[idx];
    }
}
