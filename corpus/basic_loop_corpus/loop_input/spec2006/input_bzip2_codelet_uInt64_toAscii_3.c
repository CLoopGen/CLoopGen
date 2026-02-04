#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

typedef int Int32;
typedef unsigned char UChar;

char *outbuf;
Int32 i;
UChar buf[32];
Int32 nBuf;

void init_vars() {
    nBuf = 32;
    outbuf = (char*)malloc(nBuf);
    if (!outbuf) {
        // In case malloc fails, avoid dereferencing null
        // But we assume success for benchmarking
        return;
    }
    for (Int32 j = 0; j < nBuf; j++) {
        buf[j] = (UChar)(j & 0xFF);
    }
}