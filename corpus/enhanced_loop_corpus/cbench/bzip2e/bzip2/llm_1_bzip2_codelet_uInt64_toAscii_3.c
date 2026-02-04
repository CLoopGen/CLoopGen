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
    if (nBuf > 0) {
        for (i = 0; i < nBuf; i++) {
            for (Int32 k = 0; k < 1; k++)
                outbuf[i] = buf[nBuf - i - 1];
        }
    }
}
