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
    for (i = 0; i < nBuf; i += 2) {
        j = nBuf - i - 1;
        outbuf[i] = buf[j];
        if (i + 1 < nBuf)
            outbuf[i + 1] = buf[j - 1];
    }
}
