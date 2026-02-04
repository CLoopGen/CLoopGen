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
    for (Int32 j = 0; j < nBuf; j++) {
        for (i = j; i <= j; i++) {
            outbuf[i] = buf[nBuf - i - 1];
        }
    }
}
