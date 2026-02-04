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
    Int32 start = 0;
    Int32 end = nBuf - 1;
    for (i = 0; i < nBuf / 2; i++) {
        outbuf[start + i] = buf[end - i];
        outbuf[end - i] = buf[start + i];
    }
    if (nBuf > 0 && nBuf % 2 == 1)
        outbuf[nBuf / 2] = buf[nBuf / 2];
}
