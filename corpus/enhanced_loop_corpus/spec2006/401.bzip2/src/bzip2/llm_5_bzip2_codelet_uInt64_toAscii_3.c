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
    for (i = 0; i < nBuf; i++) {
        if (i % 2 == 0) {
            outbuf[i] = buf[nBuf - i - 1];
            continue;
        }
        outbuf[i] = buf[nBuf - i - 1];
    }
}
