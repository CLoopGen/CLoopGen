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
    while (start <= end) {
        outbuf[start] = buf[end - start];
        if (start != end)
            outbuf[end] = buf[start];
        start++;
        end--;
    }
}
